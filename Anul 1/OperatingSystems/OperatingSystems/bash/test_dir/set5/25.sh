#!/bin/bash

while ! [ $# -eq 0 ]; do
	if [ -f $1 ]; then
		cat $1 | head -n 10
	elif [ -d $1 ]; then
		ls -l > "$1/$1.info"
	else
		echo Other
	fi
	shift
done
