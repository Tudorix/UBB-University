#!/bin/bash

if ! [ $# -eq 1 ];then
	echo Not enough arguments
	exit 1
fi

if ! [ -d $1 ]; then
	echo Not a dir
	exit 1
fi

total=0
for F in `find $1 -name "*.c" `; do
	count=`grep -Ev '^([[:space:]])*$' -c $F `
	total=$((total + count))
done

echo $total
