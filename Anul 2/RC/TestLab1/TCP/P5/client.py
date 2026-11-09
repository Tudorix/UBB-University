import socket
import struct

sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sock.connect(('127.0.0.1',3663))

n = input("N = ")
n = int(n)

data = struct.pack("!i",n);
sock.sendall(data)

for i in range(n):
    print(f"Student {i}:")
    Name = input("Nume : ")
    l = len(Name)
    data = struct.pack("!i",l)
    sock.sendall(data)
    sock.sendall(Name.encode())
    
    K = input("Nr note : ")
    K = int(K)
    data = struct.pack("!i",K)
    sock.sendall(data)
    
    for j in range(K):
        x = input("Note : ")
        x = int(x)
        data = struct.pack("!i",x)
        sock.sendall(data)

data = sock.recv(4)
medie = struct.unpack("!i",data)[0]

data = sock.recv(4)
leng = struct.unpack("!i",data)[0]

data = sock.recv(leng)
data = data.decode()

print(f"Nume : {data}")
print(f"Medie : {medie/100}")

sock.close()