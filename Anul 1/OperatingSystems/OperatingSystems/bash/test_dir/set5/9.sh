#!/bin/bash

while ! [ $# -eq 0 ]; do
	fn=$1
	shift
	word=$1
	shift

	if ! [ -f $fn ];then
		echo Nu e fisier

	else
		count=$(grep -E "$word" -c $fn)
		if [ $count -ge 3 ]; then
			echo Apare
		fi
	fi

done
