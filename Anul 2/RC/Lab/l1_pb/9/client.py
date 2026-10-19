import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((TCP_IP,TCP_PORT))

s1 = input("Give a number: ")
s2 = input("Give a number: ")

s.sendall(f"{s1} {s2}\n".encode())

result = s.recv(1024).decode()
print(result)

s.close()