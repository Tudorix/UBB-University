#!/bin/bash

if [ $# -eq 0 ]; then
	ls -la | while read -r file; do
		fname=$(echo $file | awk '{print $NF}')
		count=$(echo $fname | grep '\.txt$' -c)
		if [ $count -gt 0 ];then
			echo $file | awk '{print $1, $5}'
			lines=$(cat $fname | sort | uniq | wc -l)
			echo $lines
		fi
	done
fi
