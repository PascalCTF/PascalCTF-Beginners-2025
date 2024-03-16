#!/bin/sh

mkdir attachments
cp src/reverse2.cpp attachments/switcharoo.cpp

g++ attachments/switcharoo.cpp -o attachments/switcharoo

echo "Done"