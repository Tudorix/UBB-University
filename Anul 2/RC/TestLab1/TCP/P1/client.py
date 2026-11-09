import socket
import struct

IP = '127.0.0.1'
PORT = 3663

server_sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_sock.connect((IP,PORT))

a = input("A = ");
a = int(a)

b = input("B = ");
b = int(b)

# ! - Network Byte Order
# i - un numar pe 32 de biti
data = struct.pack("!ii",a,b)
server_sock.sendall(data)

data = server_sock.recv(4) # Nr de octeti
suma = struct.unpack("!i",data)[0] # Returneaza tuplu
print(f'Suma este: {suma}')

server_sock.close()