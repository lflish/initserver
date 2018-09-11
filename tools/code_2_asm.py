#!/bin/python
"""
shellcode 转 汇编
先把字符串形式转换为字节码shellcode
然后转换为汇编
"""
import sys
import os

from subprocess import call
from capstone import *

def str_2_bin(a):

	str_bin = bytearray()
	tmp = ""

	a = a[2:] + "\\"

	for i in a:	
		if i == '\\': 
			str_bin.append(int(tmp, 16))
		elif i == 'x' :
			tmp = ""
		else:
			tmp = tmp + i
		
	return str_bin
	
str = sys.argv[1:]

if not str :
	print "empty"
else:
	str = str[0]

shellcode = str_2_bin(str)


md = Cs(CS_ARCH_X86, CS_MODE_32)

md.syntax = CS_OPT_SYNTAX_ATT

for i in md.disasm(shellcode, 0x00):
	print ("0x%x:\t%s\t%s" % (i.address, i.mnemonic, i.op_str))

exit(0);






tmp = "./tmp.bin"

f = open(tmp, "wb");

f.write(bin_str);

f.close();

call(["objdump", "-D", "-b", "binary", "-m", "i386", tmp])

os.remove(tmp);
