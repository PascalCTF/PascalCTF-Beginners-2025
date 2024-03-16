#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from base64 import b64decode
import requests, re

def checker():
    url = f'https://{DOMAIN}/'
    r = requests.get(url)
    m = re.search(r"atob\('(.*)'\)", r.text)
    print(b64decode(m.group(1)).decode())
    
if __name__ == '__main__':
    DOMAIN = "staticflag.challs.pascalctf.it"

    checker()