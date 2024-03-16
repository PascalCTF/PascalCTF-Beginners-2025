#!/bin/sh

mkdir attachments
cp -r src/* attachments/
cp src/.env attachments/

sed -i 's/pascalCTF{.*}/pascalCTF{REDACTED}/g' attachments/.env

echo "Done"