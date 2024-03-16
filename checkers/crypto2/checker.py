#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from Crypto.Util.number import long_to_bytes
from pwn import remote, context

def checker():
    r = remote(DOMAIN, PORT)

    r.recvuntil(b'> ')
    r.sendline(b'1')
    r.recvuntil(b': ')
    r.sendline(b'2')
    r.recvuntil(b': ')
    r.sendline(b'15') # 40 * 10

    for _ in range(15):
        r.recvuntil(b': ')
        r.sendline(str(((1 << 40) - 1) << (40 * _)).encode())

    flag = 0
    r.recvuntil(b'[')
    for _ in range(15):
        flag |= int(r.recvuntil(b',')[:-1].decode())

    print(long_to_bytes(flag).decode())

if __name__ == '__main__':
    DOMAIN = "mindblowing.challs.pascalctf.it"
    PORT = 420
    
    context.log_level = 'error'
    
    checker()