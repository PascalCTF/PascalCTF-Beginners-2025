#!/usr/bin/env python3
from Crypto.Util.number import *
from pwn import *

# connect to the server
r = remote('0.0.0.0', 420)

# Bypass menu questions
r.recvuntil(b'> ')
r.sendline(b'1')
r.recvuntil(b': ')
r.sendline(b'2')
r.recvuntil(b': ')
r.sendline(b'15') # 40 * 10

# send masks to get 40 bits of the flag at a time
for _ in range(15):
    r.recvuntil(b': ')
    r.sendline(str(((1 << 40) - 1) << (40 * _)).encode())

flag = 0
# get the flag
r.recvuntil(b'[')
for _ in range(15):
    flag |= int(r.recvuntil(b',')[:-1].decode())

# print the flag
print(long_to_bytes(flag).decode())