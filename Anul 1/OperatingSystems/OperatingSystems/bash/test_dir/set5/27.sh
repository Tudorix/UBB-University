#!/bin/bash

while ! [ $# -eq 0 ]; do
	if [ -d $1 ];then
		for F in $(find "$1"); do
			if [ -d "$F" ];then
				count=$(ls -la $F | awk '{print $NF}'| grep -Evc '^\.')
				if [ $count -gt 1 ]; then
					echo $F
				fi
			fi

			if [ -f $F ]; then
				count=$(cat $F | wc -l)
				count_empty=$(cat $F | sort | grep -E '.' -c)
				if [ $count_empty -gt 10 ];then
					echo $F
				fi
			fi
		done	
	fi
	shift
done
