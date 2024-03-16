#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import requests

def checker():
    code = requests.get(f"https://{DOMAIN}/adminSupport").json()['response']
    if code != "up-up-down-down-left-right-left-right-B-A":
        print("Code is incorrect")

    flag = requests.post(f"https://{DOMAIN}/adminSupport", json={"code":code}).text
    print(flag)

if __name__ == '__main__':
    DOMAIN = "kontactmi.challs.pascalctf.it"

    checker()