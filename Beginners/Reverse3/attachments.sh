#!/bin/sh

mkdir attachments
cp src/*.c attachments/
cp src/*.h attachments/

cd attachments
gcc main.c util.c -lcurl -o kontactmi

echo "Done"