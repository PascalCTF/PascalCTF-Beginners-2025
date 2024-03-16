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