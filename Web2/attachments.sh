#!/bin/sh

mkdir attachments
cp -r src/* attachments/

sed -i 's/pascalCTF{.*}/pascalCTF{REDACTED}/g' attachments/docker-compose.yml

echo "Done"