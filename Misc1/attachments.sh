#!/bin/sh

(export $(cat src/.env | xargs) && python3 src/misc1.py)
cp src/misc1.py basenhex.py

mkdir attachments
mv basenhex.py attachments/
mv output.txt attachments/

echo "Done"