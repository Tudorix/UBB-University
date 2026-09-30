#!/bin/bash

while ! [ $# -eq 0 ]; do
	arg="$1"
	if [ -d $1 ]; then
		for P in $(find $arg); do
			if [ -d $P ]; then
				count=$(ls -la $P | wc -l )
				if [ $count -eq 3 ]; then
					echo $P
				fi
			fi

			if [ -f $P ]; then
				count=$(cat $P | wc -w )
				if [ $count -eq 0 ]; then
					echo $P
				fi
			fi
		done 
	fi
	shift
done
