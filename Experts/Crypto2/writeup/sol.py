#!/usr/bin/env python3
from Crypto.Util.number import long_to_bytes, bytes_to_long
from randcrack import RandCrack
from pwn import *

r = process(['python3', 'src/crypto2.py'])
rc = RandCrack()

def sendmessage(choice):
    r.recvuntil(b'> ')
    r.sendline(str(choice).encode())

def find_key(plaintext: int, ciphertext:int):
    c = ciphertext & 0xffffffff
    p = plaintext  & 0xffffffff
    key = 0

    for i in reversed(range(4)):
        a = p >> (i*8)
        b = c >> (i*8)

        key |= ((a & 0xf)  ^ (b & 0xf))  << 4
        key |= ((a & 0xf0) ^ (b & 0xf0)) >> 4
        
        key <<= 8
        
    return long_to_bytes(key)[:-1]

def find_plain(key: int, ciphertext: int):
    plaintext = 0

    for i in reversed(range(len(long_to_bytes(ciphertext)))):
        a = key        >> (i*8)
        b = ciphertext >> (i*8)

        plaintext |= (((a & 0xf0) >> 4) ^ (b & 0xf)) 
        plaintext |= ((a & 0xf) ^ ((b & 0xf0) >> 4)) << 4
        
        plaintext <<= 8
        
    return long_to_bytes(plaintext)[:-1]

for i in range(624):
    sendmessage(1)
    r.recvuntil(b'plaintext: ')
    r.sendline(b'A' * 5)
    enc = bytes.fromhex(r.recvline().strip().decode().split(',')[0])
    key = find_key(bytes_to_long(b'A' * 5), bytes_to_long(enc))
    key = bytes_to_long(key)
    rc.submit(key)
    
sendmessage(3)
flag = bytes.fromhex(r.recvline().strip().decode())
key = rc.predict_getrandbits(32).to_bytes(4, 'big')
print(find_plain(bytes_to_long(key * (len(flag) // len(key))), bytes_to_long(flag)).decode())