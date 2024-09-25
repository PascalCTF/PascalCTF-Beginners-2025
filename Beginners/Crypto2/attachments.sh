#!/bin/sh

cp src/crypto2.py mindblowing.py

sed -i 's/pascalCTF{.*}/pascalCTF{REDACTED}/g' mindblowing.py

mkdir attachments
mv mindblowing.py attachments/

echo "Done"