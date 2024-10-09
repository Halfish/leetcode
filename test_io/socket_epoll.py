import socket
import select
import click


@click.command()
@click.option(
    "--mode",
    type=click.Choice(["server", "client"]),
    required=True,
    help="Choose to run as server or client",
)
@click.option("--host", default="localhost", help="Host to connect or bind to")
@click.option("--port", default=8080, help="Port to connect or bind to", type=int)
def main(mode, host, port):
    if mode == "server":
        run_server(host, port)
    elif mode == "client":
        run_client(host, port)


def run_server(host, port):
    # 创建服务器套接字
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((host, port))
    server_socket.listen()

    # 设置为非阻塞模式
    server_socket.setblocking(False)

    # 创建一个 epoll 对象
    epoll = select.epoll()

    # 注册服务器套接字的读事件（EPOLLIN）
    epoll.register(server_socket.fileno(), select.EPOLLIN)

    # 字典用于存储套接字和地址信息
    fd_to_socket = {server_socket.fileno(): server_socket}
    message_queues = {}

    print(f"服务器正在监听 {host}:{port}...")

    try:
        while True:
            # 等待事件发生
            events = epoll.poll()

            for fd, event in events:
                s = fd_to_socket[fd]

                # 如果是服务器套接字，有新的连接
                if s is server_socket:
                    client_socket, client_address = s.accept()
                    print(f"新连接来自 {client_address}")
                    client_socket.setblocking(False)

                    # 注册新客户端套接字的读事件
                    epoll.register(client_socket.fileno(), select.EPOLLIN)
                    fd_to_socket[client_socket.fileno()] = client_socket
                    message_queues[client_socket] = b"Hello from server!"

                # 如果是客户端套接字，有数据可读
                elif event & select.EPOLLIN:
                    data = s.recv(1024)
                    if data:
                        print(f"收到来自客户端的数据: {data.decode()}")
                        epoll.modify(fd, select.EPOLLOUT)  # 修改为写事件
                    else:
                        # 客户端已关闭
                        print(f"客户端 {s.getpeername()} 断开连接")
                        epoll.unregister(fd)
                        s.close()
                        del fd_to_socket[fd]
                        del message_queues[s]

                # 如果是客户端套接字，可写
                elif event & select.EPOLLOUT:
                    next_msg = message_queues[s]
                    s.send(next_msg)
                    print(f"发送消息给客户端: {next_msg.decode()}")
                    epoll.modify(fd, select.EPOLLIN)  # 修改回读事件

                # 异常处理
                elif event & select.EPOLLHUP:
                    print(f"套接字异常: {s.getpeername()}")
                    epoll.unregister(fd)
                    s.close()
                    del fd_to_socket[fd]
                    if s in message_queues:
                        del message_queues[s]

    finally:
        epoll.unregister(server_socket.fileno())
        epoll.close()
        server_socket.close()


def run_client(host, port):
    # 创建客户端套接字
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    print(f"连接到服务器 {host}:{port}")
    client_socket.connect((host, port))

    try:
        # 发送消息到服务器
        message = "Hello from client!"
        print(f"发送消息: {message}")
        client_socket.sendall(message.encode())

        # 接收来自服务器的响应
        data = client_socket.recv(1024)
        print(f"收到来自服务器的消息: {data.decode()}")

    finally:
        print("关闭连接")
        client_socket.close()


if __name__ == "__main__":
    main()
