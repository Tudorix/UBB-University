#!/bin/bash

if [ $# -eq 0 ]; then
	exit 1
fi

while true; do
	for P in "$@"; do
		for PID in $(pgrep -x $P); do
			kill -9 $PID
			echo Kill Confirmed
		done
	done
	sleep 1
done
