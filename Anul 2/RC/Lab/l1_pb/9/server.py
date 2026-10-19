import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((TCP_IP,TCP_PORT))
s.listen(1)

while(1):
    conn, addr = s.accept()
    print("Connection address: ", addr)
    s1, s2 = conn.recv(2048).decode().strip().split()

    s3 = ''
    for a in s1:
        if a not in s2 and a not in s3:
            s3 += a

    conn.send(s3.encode())
    conn.close()

