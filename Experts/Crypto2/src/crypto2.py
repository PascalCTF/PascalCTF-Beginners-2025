#!/usr/bin/env python3
from Crypto.Util.number import long_to_bytes, bytes_to_long
from dotenv import load_dotenv
import random, time, os

load_dotenv()
FLAG = os.getenv('FLAG', 'pascalCTF{REDACTED}')
assert FLAG.startswith('pascalCTF{')
assert FLAG.endswith('}')
random.seed(time.time())

def mysteriousFunction(plaintext: bytes, key: bytes): # idk why i added it lol
    a = bytes_to_long(plaintext)
    b = bytes_to_long(key)
    
    c, t = 0, 0
    while a > 0 and b > 0:
        v1 = (a & 0xf) ^ ((b & (0xff - 0xf)) >> 4)
        v2 = (b & 0xf) ^ ((a & (0xff - 0xf)) >> 4)
        c += (v1 | (v2 << 4)) << t
        a, b = a >> 8, b >> 8
        t += 8
        
    if a > 0:
        c += a << t
    elif b > 0:
        c += b << t
        
    return long_to_bytes(c)
    
def encrypt():
    plain = input("Enter the plaintext: ").encode()
    if bytes_to_long(plain) < 2 ** 32:
        return "Invalid plaintext."
    
    key = int(random.getrandbits(32)).to_bytes(4, 'big')
    return mysteriousFunction(plain, key * (len(plain) // len(key))).hex()

def decrypt():
    # TODO implement this function
    print("This function is not implemented yet.")

def getFlag():
    key = int(random.getrandbits(32)).to_bytes(4, 'big')
    return mysteriousFunction(FLAG.encode(), key * (len(FLAG) // len(key))).hex()

def menu():
    print("1. Encrypt")
    print("2. Decrypt")
    print("3. Get flag")
    print("4. Exit")
    
if __name__ == '__main__':
    while True:
        menu()
        choice = input("> ")
        
        if choice == "1":
            print(encrypt())
        elif choice == "2":
            decrypt()
        elif choice == "3":
            print(getFlag())
        else:
            break
        print()