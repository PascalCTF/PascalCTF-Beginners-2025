#!/bin/sh

mkdir attachments
gcc -fno-stack-protector -no-pie src/pwn1.c -o src/worm
cp src/worm attachments/worm

echo "Done"
