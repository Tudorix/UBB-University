#!/bin/bash

if ! [ $# == 3 ];then
	echo "Not enough parameters."
	exit 1
fi

if ! [ -f $1 ]; then
	echo "Not a file"
	exit 1
fi

reg='^[0-9]+$'
if ! [[ $3 =~ $reg ]] ; then
	echo "Not a number"
	exit 1
fi 

for LINE in `cat $1`; do
	count=`echo $LINE | grep "$2" -o | wc -l`
	if [ $count -eq $3 ]; then
		echo $LINE
	fi
done
