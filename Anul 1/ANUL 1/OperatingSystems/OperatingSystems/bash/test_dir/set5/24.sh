#!/bin/bash

while ! [ $# -eq 0 ]; do
	A="$1"
	shift
	B="$1"
	shift
	count=$(echo "$A" | grep -E "$B" -oc)
	if [ $count -gt 0 ];then
		echo "$A contains $B"
	fi
done
