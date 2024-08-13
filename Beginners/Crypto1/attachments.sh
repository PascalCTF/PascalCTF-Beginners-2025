#!/bin/sh

python3 src/crypto1.py
cp src/crypto1.py romans_empire.py

sed -i 's/pascalCTF{.*}/pascalCTF{REDACTED}/g' romans_empire.py

mkdir attachments
mv romans_empire.py attachments/
mv output.txt attachments/

echo "Done"