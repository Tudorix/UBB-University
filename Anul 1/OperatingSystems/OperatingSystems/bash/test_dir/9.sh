#!/bin/bash

for F in `find "$1" -type f`; do
    sum=$(sudo md5sum "$F" | awk '{print $0}')
    echo "$sum $F"
done | sort  | awk  ' {
	count[$1]++
	file[$1] = $2
}

END {
	for(f in file){
		if(count[f] > 1){
			print file[f]
		}
	}
}




'
