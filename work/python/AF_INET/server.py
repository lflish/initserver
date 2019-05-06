from socket import *

HOST = '10.250.22.66'
PORT = 6666
BUFSIZE = 1024
ADDR = (HOST, PORT)

ss = socket(AF_INET, SOCK_STREAM)
ss.bind(ADDR)

ss.listen(5)

while True:
    cs, addr = ss.accept()
    while True:
        data = cs.recv(BUFSIZE)
        if not data:
            break
        print("cs recv data = %s" % data)
        cs.send(b"I am SS")

    cs.close()
ss.close()



