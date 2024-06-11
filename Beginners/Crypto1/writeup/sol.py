#!/usr/bin/env python3
from base64 import b64decode
flag = open("output.txt", "rb").read()

for i in range(10):
    try:
        if b64decode(flag).isascii():
            flag = b64decode(flag)
        else:
            raise Exception
    except:
        flag = bytes.fromhex(flag.decode())
print(flag.decode())