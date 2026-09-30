#!/bin/bash

for P in $@; do	
	if [ -f $P ]; then
		content=`cat $P | sort | uniq -c | sort -gr | head -n 1 `
		echo $content
	fi
done
