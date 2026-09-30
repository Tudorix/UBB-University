#!/bin/bash

if ! [ -d $1 ]; then
	exit 1
fi

for FILE in `find -type f $1 | grep -E '/.{,8}\..*$'`; do
	echo $FILE
	val=`echo $FILE | grep -E '.txt$'`

	if [ "$val" != "" ];then
		cat $FILE | head	
	fi
done
