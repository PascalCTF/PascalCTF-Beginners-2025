#!/usr/bin/env python3
def xor(a, b):
    return bytes([x ^ y for x, y in zip(a, b)])

KEY = "*7^tVr4FZ#7S4RFNd2"
ENC = "xR\x08G$G\x07\x19kPhgCa5~\t\x01"

flag = xor(KEY.encode(), ENC.encode()).decode()
print(f"pascalCTF{{{flag}}}")