# MindBlowing
## Challenge
This challenge offers a service that computes the **bitwise AND** between a sentence (likely the flag) and a series of integers provided by the user. To make everything more interesting, each integer must have no more than *40 bits set to 1*. Once the calculations are done, the challenge outputs an array of results.<br>

There are several strategies to solve this challenge. One approach involves sending approximately **15 integers**, each with 40 consecutive bits set to 1, and progressively *right-shifted* by `40 * x`, where `x` is the index of the integer. Afterward, the flag can be recovered by computing the *bitwise OR* of the results array and converting the resulting integer to bytes (in big-endian order, of course). 

## Solution
```py
#!/usr/bin/env python3
from Crypto.Util.number import *
from pwn import *

# connect to the server
r = remote('0.0.0.0', 420)

# Bypass menu questions
r.recvuntil(b'> ')
r.sendline(b'1')
r.recvuntil(b': ')
r.sendline(b'2')
r.recvuntil(b': ')
r.sendline(b'15') # 40 * 10

# send masks to get 40 bits of the flag at a time
for _ in range(15):
    r.recvuntil(b': ')
    r.sendline(str(((1 << 40) - 1) << (40 * _)).encode())

flag = 0
# get the flag
r.recvuntil(b'[')
for _ in range(15):
    flag |= int(r.recvuntil(b',')[:-1].decode())

# print the flag
print(long_to_bytes(flag).decode())
```

## Author
**Author**: [`@AlBovo`](https://github.com/AlBovo/) <br>
**Date**: 2024-09-20 <br>
**Category**: Cryptography