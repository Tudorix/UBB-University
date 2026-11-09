import socket
import struct

sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sock.connect(('127.0.0.1',8888))

# Server Case
print("I am active")
port = input("Input the port : ")
port = int(port)
        
udp_sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
udp_sock.bind(('127.0.0.1',port))

ip = '127.0.0.1'
l = len(ip)
data = struct.pack("!i",l)
sock.sendall(data)
sock.sendall(ip.encode())

data = struct.pack("!i",port)
sock.sendall(data);

server = ((ip,port))

data ,addr = udp_sock.recvfrom(4)
l = struct.unpack("!i",data)[0]
    
data, addr = udp_sock.recvfrom(l)
print("Received:", data.decode('utf-8'))
print("From:", addr)

while True:
    cuv = input("Cuvant: ")

    if len(cuv) < 2:
        print("Cuvant invalid! Ai castigat!")
        
        stop = "STOP".encode()
        udp_sock.sendto(struct.pack("!i", len(stop)), addr)
        udp_sock.sendto(stop, addr)
        break

    ultimele = cuv[-2:]

    data = cuv.encode('utf-8')
    l = len(data)

    udp_sock.sendto(struct.pack("!i", l), addr)
    udp_sock.sendto(data, addr)

    data, addr = udp_sock.recvfrom(4)
    l = struct.unpack("!i", data)[0]

    data, addr = udp_sock.recvfrom(l)
    cuv_primit = data.decode('utf-8')

    if cuv_primit == "STOP":
        print("Ai castigat!")
        break

    print("Received:", cuv_primit)

    if len(cuv_primit) < 2 or cuv_primit[:2] != ultimele:
        print("Cuvant invalid! Ai castigat!")

        stop = "STOP".encode()
        udp_sock.sendto(struct.pack("!i", len(stop)), addr)
        udp_sock.sendto(stop, addr)
        break

    ultimele = cuv_primit[-2:]
    
    

