from Crypto.Util.number import getPrime,bytes_to_long
import os

FLAG = os.environ["FLAG"]
assert FLAG.startswith("pascalCTF{")
assert FLAG.endswith("}")

e = 65537

alice_p, alice_q = getPrime(1024), getPrime(1024)
alice_n = alice_p * alice_q

print(f"hi, i'm Alice, my public parameters are:\nn={alice_n}\ne={e}")

def sendToAlice(msg):
    pt = bytes_to_long(msg.encode())
    assert pt < alice_n
    ct = pow(pt, e, alice_n)
    print(f"bob: {ct}")

bob_p, bob_q = getPrime(1024), getPrime(1024)
bob_n = bob_p * bob_q

print(f"hi Alice! i'm Bob, my public parameters are:\nn={bob_n}\ne={e}")

def sendToBob(msg):
    pt = bytes_to_long(msg.encode())
    assert pt < bob_n
    ct = pow(pt, e, bob_n)
    print(f"alice: {ct}")


alice_favourite_number = bytes_to_long(FLAG.encode())
assert alice_favourite_number < 2**500

sendToBob("let's play a game, you have to guess my favourite number")

upperbound = 2**501
lowerbound = 0
while upperbound - lowerbound > 1:
    mid = (upperbound + lowerbound) // 2
    sendToAlice(f"Is your number greater than {mid}?")
    if alice_favourite_number > mid:
        sendToBob(f"Yes!, my number is greater than {mid}")
        lowerbound = mid
    else:
        sendToBob(f"No!, my number is lower or equal to {mid}")
        upperbound = mid

sendToAlice(f"so your number is {upperbound}?")
assert upperbound == alice_favourite_number
sendToBob("yes it is!")
sendToAlice("that's a pretty cool number")