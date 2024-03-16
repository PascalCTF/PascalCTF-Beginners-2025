import requests

code = requests.get(f"https://kontactmi.challs.pascalctf.it/adminSupport").json()['response']

flag = requests.post(f"https://kontactmi.challs.pascalctf.it/adminSupport", json={"code":code}).text
print(flag)