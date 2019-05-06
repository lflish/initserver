from socket import *


HOST = ('./python.sock')
BUFSIZE = 1024

ss = socket(AF_UNIX, SOCK_STREAM)
ss.bind(HOST)

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
