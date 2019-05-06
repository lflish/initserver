from socket import *

HOST = '10.250.22.66'
PORT = 6666
BUFSIZE = 1024
ADDR = (HOST, PORT)

cs = socket(AF_INET, SOCK_STREAM)
cs.connect(ADDR)


cs.send(b"I am Client Socket")

data = cs.recv(BUFSIZE)

print(data)

cs.close()
