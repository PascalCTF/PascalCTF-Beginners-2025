# Romañs Empyre
## Challenge
This challenge `"encrypts"` the flag in a very simple way, **randomly** choosing a key used to encode the flag using the [`Caesar Cipher`](https://en.wikipedia.org/wiki/Caesar_cipher). The result of this encryption can be found in `output.txt` and can be decrypted using [`cyberchef.org`](https://gchq.github.io/CyberChef/) or by using the Python writeup attached to this challenge.

## Solution
```py
#!/usr/bin/env python3
import string
alphabet = string.ascii_letters + string.digits + "{}_-.,/%?$!@#"

def romanize(input_string):
    for key in range(1, len(alphabet)):
        result = [""] * len(input_string)
        for i, c in enumerate(input_string):
            result[i] = alphabet[(alphabet.index(c) + key) % len(alphabet)]
        result = "".join(result)

        if "pascalCTF{" in result:
            return result

if __name__ == "__main__":
    enc_flag = open("output.txt", "r").read().strip()
    print(romanize(enc_flag))
```

## Author
**Author**: [`@AlBovo`](https://github.com/AlBovo/) <br>
**Date**: 2024-07-19 <br>
**Category**: Cryptography