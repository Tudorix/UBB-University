#!/bin/bash

if [ $# -eq 0 ]; then
	 echo No argumets
	 exit 1
fi

check=0
fname=""
while ! [ $check -eq $# ]; do
	read -p "Enter a filename " fname
	for P in $@; do
		if [ -f $fname ]; then
			c=$(cat $fname | grep -E "$P" -c)
			if [ "$c" -gt 0 ]; then
				check=$((check + 1))
			fi
		fi
	done 
done
