# My favourite number
## Challenge
This challenge provides an output file, which contains a conversation between Alice and Bob **encrypted with RSA**, where Bob guesses Alice's favourite number, by doing a binary search. For each message Alice responds with a yes or no answer to the question is your number larger than X? Until the correct one is found, this number is `long_to_bytes()` of the flag

The key insight is that we can encrypt, using Bob's public key the message that Alice would send for both the affirmative and negative case and check which one matches, following the whole conversation and finding out the value

## Solution
```py
#!/usr/bin/env python3
from Crypto.Util.number import getPrime,bytes_to_long,long_to_bytes

f=open("output.txt","r")

n= #bob_n
e=65537

def sendToBob(msg):
    pt=bytes_to_long(msg.encode())
    ct=pow(pt,e,n)
    return f"alice: {ct}"

#skip first messages
for i in range(7):
    f.readline()

upperbound=2**501
lowerbound=0
while(upperbound-lowerbound>1):
    mid=(upperbound+lowerbound)//2
    f.readline()
    response=f.readline()
    if(response.strip()==sendToBob(f"Yes!, my number is greater than {mid}")):
        lowerbound=mid
    else:
        upperbound=mid

#print the flag
print(long_to_bytes(upperbound).decode())
```

## Author
**Author**: [`@DavideGianessi`](https://github.com/DavideGianessi/) <br>
**Date**: 2024-03-19 <br>
**Category**: Cryptography
