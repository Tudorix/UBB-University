#!/bin/bash

for F in $(find -type f); do
	if [[ $F =~ \.c$  ]]; then
		echo Trebuia sa te sterg
	else
		echo $F
	fi
done | sort
