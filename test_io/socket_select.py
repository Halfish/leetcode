import click
import socket
import select


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

    # 将服务器套接字设置为非阻塞
    server_socket.setblocking(False)

    # 初始化需要监视的读写文件描述符列表
    inputs = [server_socket]
    outputs = []
    message_queues = {}

    print(f"服务器正在监听 {host}:{port}...")

    while inputs:
        readable, writable, exceptional = select.select(inputs, outputs, inputs)

        for s in readable:
            if s is server_socket:
                # 处理新连接
                client_socket, client_address = s.accept()
                print(f"新连接来自 {client_address}")
                client_socket.setblocking(False)
                inputs.append(client_socket)
                message_queues[client_socket] = b"Hello from server!"

            else:
                # 处理已连接客户端的数据接收
                data = s.recv(1024)
                if data:
                    print(f"收到来自客户端的数据: {data.decode()}")
                    outputs.append(s)
                else:
                    print(f"客户端 {s.getpeername()} 断开连接")
                    if s in outputs:
                        outputs.remove(s)
                    inputs.remove(s)
                    s.close()
                    del message_queues[s]

        for s in writable:
            try:
                next_msg = message_queues[s]
                s.send(next_msg)
                print(f"发送消息给客户端: {next_msg.decode()}")
                outputs.remove(s)
            except Exception as e:
                print(f"发送数据出错: {e}")

        for s in exceptional:
            print(f"套接字异常: {s.getpeername()}")
            inputs.remove(s)
            if s in outputs:
                outputs.remove(s)
            s.close()
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
