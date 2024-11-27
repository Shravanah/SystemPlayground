#!/bin/bash
K=$1
file=$2
cat $file|
tr -sc 'A-Za-z' '\n'|
tr 'A-Z' 'a-z'|
sort |
uniq -c|
sort -rn|
head -n $K
