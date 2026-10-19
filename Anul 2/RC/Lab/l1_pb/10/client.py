import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((TCP_IP,TCP_PORT))

s1 = input("Give a string: ")
s2 = input("Give a string: ")

s.sendall(f"{s1}\n{s2}\n".encode())

result, cnt = s.recv(2048).decode().strip().split()
print(result , cnt)

s.close()