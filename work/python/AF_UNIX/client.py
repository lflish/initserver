from socket import *

HOST = './python.sock'
BUFSIZE = 1024

cs = socket(AF_UNIX, SOCK_STREAM)
cs.connect(HOST)

cs.send(b"I am Client Socket")

data = cs.recv(BUFSIZE)

print(data)

cs.close()
