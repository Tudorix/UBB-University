import socket
import struct

sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sock.connect(('127.0.0.1',3663))

n = input("N = ")
try:
    n = int(n)
except:
    exit()
    
data = struct.pack("!i",n)
sock.sendall(data)
    
for i in range(n):
    n = input(f"Nr {i + 1} = ")
    n = int(n)
    data = struct.pack("!i",n)
    sock.sendall(data)
    
data = sock.recv(4)
n = struct.unpack("!i",data)[0]

for i in range(n):
    data = sock.recv(4)
    x = struct.unpack("!i",data)[0]
    print(x)
    
sock.close()