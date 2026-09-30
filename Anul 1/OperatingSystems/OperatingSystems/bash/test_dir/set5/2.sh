#!/bin/bash

if ! [ $# -eq 1 ];then
	echo Not enough arguments
	exit 1
fi

if ! [ -d $1 ]; then
	echo Not a dir
	exit 1
fi

for F in `find $1 -name "*.c" `; do
	count=`grep -Ev '^([[:space:]])*$' -c $F `
	echo $count
done
