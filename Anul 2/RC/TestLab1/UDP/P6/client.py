import socket
import struct

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server = ('127.0.0.1',3663)

a = input("A = ")
a = int(a)

b = input("B = ")
b = int(b)

data = struct.pack("!ii",a,b)
sock.sendto(data,server)

data, addr = sock.recvfrom(4)
suma = struct.unpack("!i",data)[0]
print(f"Suma : {suma}")

sock.close()