#!/bin/sh

(export $(cat src/.env | xargs) && python3 src/crypto3.py > src/output.txt)
cp src/crypto3.py myfavourite.py

mkdir attachments
mv myfavourite.py attachments/
mv src/output.txt attachments/

echo "Done"