import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((TCP_IP,TCP_PORT))
s.listen(1)

while(1):
    conn, addr = s.accept()
    print("Connection address: ", addr)
    data = b""

    while data.count(b"\n") < 2:
        chunk = conn.recv(1024)
        if not chunk:
            break
        data += chunk

    s1, s2 = data.decode().splitlines()

    s3 = ''
    cnt = 0
    f = {}

    for i in range(0,min(len(s1),len(s2))):
        if s1[i] == s2[i] :
            f[s1[i]] = f.get(s1[i], 0) + 1

    cnt = 0
    for c,v in f.items():
        if v > cnt:
            cnt = v
            s3 = c

    if cnt == 0:
        s3 = '-'
    
    conn.sendall(f"{s3} {cnt}\n".encode());
    conn.close()

