#!/bin/bash

fnmae=""
while [ "$fname" != "stop" ]; do
	read -p "Enter a filename " fname
	if [ -f $fname ]; then
		if echo $fname | grep -E '*.txt$'; then
			sed -En '1,1p' $fname | wc -w
		fi
	fi	
done
