#!/bin/sh

mkdir attachments
gcc -fno-stack-protector -no-pie -static src/pwn2.c -o attachments/unpwnable
cp attachments/unpwnable src/unpwnable

echo "Done"
