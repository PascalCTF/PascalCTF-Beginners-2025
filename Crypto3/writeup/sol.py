#!/usr/bin/env python3
from Crypto.Util.number import getPrime,bytes_to_long,long_to_bytes

f=open("output.txt","r")

n= #bob_n
e=65537

def sendToBob(msg):
    pt=bytes_to_long(msg.encode())
    ct=pow(pt,e,n)
    return f"alice: {ct}"

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
print(long_to_bytes(upperbound).decode())
