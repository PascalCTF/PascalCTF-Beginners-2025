#!/bin/sh

python3 src/misc1.py
cp src/misc1.py basenhex.py

sed -i 's/pascalCTF{.*}/pascalCTF{REDACTED}/g' basenhex.py

mkdir attachments
mv basenhex.py attachments/
mv output.txt attachments/

echo "Done"