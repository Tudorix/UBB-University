import socket

IP = "192.168.40.153"
PORT = 6767

c = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
c.connect((IP,PORT))

s = input("String:")
c.sendall(f"{s}\n".encode())
