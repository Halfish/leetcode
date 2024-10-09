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
    # 创建并设置服务器套接字
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen()
    server_socket.setblocking(False)

    # 创建一个poll对象
    poller = select.poll()

    # 注册服务器套接字到poller中，监听输入事件
    poller.register(server_socket, select.POLLIN)

    message_queues = {}
    fd_to_socket = {server_socket.fileno(): server_socket}  # 文件描述符到套接字的映射

    print(f"服务器正在监听 {host}:{port}...")

    while True:
        events = poller.poll()

        for fd, flag in events:
            s = fd_to_socket[fd]

            if s is server_socket:
                client_socket, client_address = s.accept()
                print(f"新连接来自 {client_address}")
                client_socket.setblocking(False)

                # 注册新的客户端套接字到poller中，监听输入事件
                poller.register(client_socket, select.POLLIN)
                fd_to_socket[client_socket.fileno()] = client_socket
                message_queues[client_socket] = b"Hello from server!"

            elif flag & select.POLLIN:
                data = s.recv(1024)
                if data:
                    print(f"收到来自客户端的数据: {data.decode()}")
                    poller.modify(s, select.POLLOUT)
                else:
                    print(f"客户端 {s.getpeername()} 断开连接")
                    poller.unregister(s)
                    s.close()
                    del fd_to_socket[fd]
                    del message_queues[s]

            elif flag & select.POLLOUT:
                next_msg = message_queues[s]
                s.send(next_msg)
                print(f"发送消息给客户端: {next_msg.decode()}")
                poller.modify(s, select.POLLIN)

            elif flag & select.POLLERR:
                print(f"套接字异常: {s.getpeername()}")
                poller.unregister(s)
                s.close()
                del fd_to_socket[fd]
                if s in message_queues:
                    del message_queues[s]


def run_client(host, port):
    # 创建客户端套接字
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    print(f"连接到服务器 {host}:{port}")
    client_socket.connect((host, port))

    try:
        message = "Hello from client!"
        print(f"发送消息: {message}")
        client_socket.sendall(message.encode())

        data = client_socket.recv(1024)
        print(f"收到来自服务器的消息: {data.decode()}")

    finally:
        print("关闭连接")
        client_socket.close()


if __name__ == "__main__":
    main()
