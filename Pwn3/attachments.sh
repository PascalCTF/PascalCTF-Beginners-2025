#!/bin/sh

mkdir attachments
gcc src/pwn3.c -o src/elia
cp src/elia attachments/

echo "Done"
