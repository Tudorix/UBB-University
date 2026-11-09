import socket
import struct

IP = '127.0.0.1'
PORT = 3663

server_sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_sock.connect((IP,PORT))

a = input("Sir = ");

# ! - Network Byte Order
# i - un numar pe 32 de biti
data = struct.pack("!i",len(a))
server_sock.sendall(data)
server_sock.sendall(a.encode())

data = server_sock.recv(8);
rez = struct.unpack("!ii",data)
print(f'Vocale : {rez[0]}\nConsoane : {rez[1]}\n')

server_sock.close()