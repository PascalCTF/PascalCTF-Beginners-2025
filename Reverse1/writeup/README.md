# X-Ray
## Challenge
This challenge reads a "*license*" and then checks whenever its valid.
The main issue here it's that the encryption of the license was made using **XOR**, so the it can be decrypted as follows.

## Solution
```py
#!/usr/bin/env python3
def xor(a, b):
    return bytes([x ^ y for x, y in zip(a, b)])

KEY = "*7^tVr4FZ#7S4RFNd2"
ENC = "xR\x08G$G\x07\x19kPhgCa5~\t\x01"

flag = xor(KEY.encode(), ENC.encode()).decode()
print(f"pascalCTF{{{flag}}}")
```

## Author
**Author**: [`@AlBovo`](https://github.com/AlBovo/) <br>
**Date**: 2024-08-12 <br>
**Category**: Reverse Engineering