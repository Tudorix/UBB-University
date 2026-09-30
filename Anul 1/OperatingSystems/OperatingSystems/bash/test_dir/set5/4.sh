#!/bin/bash

while [ $# != 0 ]; do
	if [ -f $1 ]; then
		echo File
	elif [ -d $1 ]; then
		echo Dir
	elif echo $1 | grep -E '^[0-9]*$'; then
		echo Number
	else
		echo Other
	fi
	shift
done
