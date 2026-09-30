#!/bin/bash

if [ $# -eq 0 ]; then
	while true; do
	    for U in $(ps -ef | awk '{print $1}' ); do
			ps -ef | grep -E "$U" | sort | uniq
		done
		sleep 1
	done
else
	while true; do
		for U in $@; do
			ps -ef | grep -E "$U" | sort | uniq
		done
		sleep 1
	done
fi
