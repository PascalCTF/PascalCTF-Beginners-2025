#!/usr/bin/env python3
from Crypto.Util.number import long_to_bytes, bytes_to_long
import random, time, os

FLAG = os.environ.get('FLAG', 'pascalCTF{REDACTED}')
assert FLAG.startswith('pascalCTF{')
assert FLAG.endswith('}')
random.seed(time.time())

def sussyFunction(val1: bytes, val2: bytes): # idk why i added it lol
    a = bytes_to_long(val1)
    b = bytes_to_long(val2)
    
    if a < 0x10 or b < 0x10:
        return a ^ b
    
    c, t = 0, 0
    while a > 0 and b > 0:
        v1 = (a & 0xf) ^ (b & (0xff - 0xf))
        v2 = (b & 0xf) ^ (a & (0xff - 0xf))
        c += (v2 | (v1 << 4)) << t
        a, b = a >> 8, b >> 8
        t += 8
        
    if a > 0:
        c += a << t
    elif b > 0:
        c += b << t
        
    return long_to_bytes(c)
    
def encrypt():
    plain = input("Enter the plaintext: ").encode()
    key = int(random.randint(1 << 32)).to_bytes(4, 'big')
    return sussyFunction(plain, key).hex()

def decrypt():
    #TODO implement this function
    print("This function is not implemented yet.")

def getFlag():
    key = int(random.randint(1 << 32)).to_bytes(4, 'big')
    return sussyFunction(FLAG.encode(), key).hex()

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
            print(decrypt())
        elif choice == "3":
            print(getFlag())
        else:
            break