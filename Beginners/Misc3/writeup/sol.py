import pyshark, re

capture = pyshark.FileCapture('misc3.pcapng', display_filter='dns.a') # open file and get all requests
regex = r'pascalCTF{.*?}' # regex to match flag format

flag = ''
for packet in capture:
    query : str = packet.dns.qry_name
    if len(data := query.split('.')) == 3:
        flag += data[0]

flag = bytes.fromhex(flag).decode('utf-8') # convert hex to ascii
print(re.findall(regex, flag)[0]) # print the flag