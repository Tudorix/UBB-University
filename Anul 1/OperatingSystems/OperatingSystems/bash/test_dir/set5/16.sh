#!/bin/bash

while true; do
	for P in $@; do
		pgrep -x "$P" | while read -r PID; do	
			kill -9 "$PID"
		done
	done
done
