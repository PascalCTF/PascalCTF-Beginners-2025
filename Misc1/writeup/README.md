# Base N' Hex
## Challenge
This challenge `"encrypts"` the flag in a very simple way, **randomly** choosing whether to encode the flag in *base64* or *hexadecimal* for **10 times**. The result of this encryption can be found in `output.txt` and can be decrypted using [`cyberchef.org`](https://gchq.github.io/CyberChef/) or by using the Python writeup attached to this challenge.

## Solution
```py
#!/usr/bin/env python3
from base64 import b64decode
flag = open("output.txt", "rb").read()

for i in range(10):
    try:
        if b64decode(flag).isascii():
            flag = b64decode(flag)
        else:
            raise Exception
    except:
        flag = bytes.fromhex(flag.decode())
print(flag.decode())
```

## Author
**Author**: [`@AlBovo`](https://github.com/AlBovo/) <br>
**Date**: 2024-06-11 <br>
**Category**: Miscellaneous