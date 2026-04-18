#!/bin/bash

if [ $# -lt 1 ]; then
	echo Not enough arguments
	exit 1
fi

if ! [ -d $1 ];then
	echo Not a dir
	exit 1
fi

count=0
for F in $(find $1 -name "*.c"); do
	nr=`wc -l < $F`
	if [ $nr -gt 500 ] ; then
		echo $F , $nr	
		count=$(($count + 1))
	fi	

	if [ $count -eq 2 ]; then
		break
	fi
done
