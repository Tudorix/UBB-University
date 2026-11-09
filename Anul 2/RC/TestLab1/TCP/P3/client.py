import socket
import struct

IP = '127.0.0.1'
PORT = 3663

server_sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_sock.connect((IP,PORT))

print("Calculator menu")
print("1 - Addition")
print("2 - Substitution")
print("3 - Multiplication")
print("4 - Exit")

while True:    
    x = input("Enter option : ")
    x = int(x)
    
    data = struct.pack("!i",x)
    server_sock.sendall(data)
    
    if x == 4:
        break
    
    n = server_sock.recv(4)
    n = struct.unpack("!i",n)[0]
    
    if n == 200:
        a = input("First number : ")
        a = int(a)
        
        b = input("Second number : ")
        b = int(b)
        
        data = struct.pack("!ii",a,b)
        server_sock.sendall(data)
        
        data = server_sock.recv(4)
        rez = struct.unpack("!i",data)[0]
        
        print(f"Result : {rez}")
    else:
        print("Error in selecting option")
    
server_sock.close()