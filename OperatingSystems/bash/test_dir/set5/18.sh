#!/bin/bash

ls -l | while read -r F; do 
	comp=$(echo $F | awk '{print $1}' | grep -E "r" -o | wc -w)
	if [ $comp -eq 3 ]; then
		file=$(echo $F | awk '{print $NF}')
		echo $file
	fi
done
