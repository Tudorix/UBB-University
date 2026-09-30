#!/bin/bash

if ! [ $# -eq 1 ];then 
	echo Error
	exit 1
fi

if ! [ -d $1 ]; then
	echo error
	exit 1
fi

for F in `find $1 -type f -perm -222 `; do
	before=`ls -la "$F" | awk '{print $1}' `
	echo $before, $F

	chmod a-w $F
	after=`ls -la "$F" | awk '{print $1}' `
	echo $after
done
