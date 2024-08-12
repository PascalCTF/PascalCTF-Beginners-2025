# X-Ray

## Challenge
This challenge first reads the flag from the file `flag.txt` and saves it on the **stack**. Then, it requests input from the user and subsequently prints it insecurely using `printf` without any **defined format**.

This executable can therefore be exploited if the correct offsets on the stack of the flag (from 8 to 13) are found and used together with `%p` in the format `%x$p` where *x* is the offset.

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