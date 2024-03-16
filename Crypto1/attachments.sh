#!/bin/sh

(export $(cat src/.env | xargs) && python3 src/crypto1.py)
cp src/crypto1.py romans_empire.py

mkdir attachments
mv romans_empire.py attachments/
mv output.txt attachments/

echo "Done"