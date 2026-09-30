#!/bin/bash

if [ ! -d $1 ]; then
	echo Nu e director
	exit 1
fi

STATE=""

while true; do
	S=""
	for FILE in `find $1`; do
		if [ -f $FILE ]; then
			LS=`ls -l $FILE | sha1sum`
		fi
		S="$S\n$LS"
	done

	if [ -n "$STATE" ] && [ "$STATE" != "$S" ]; then
		echo Directory has changed `date`
	fi
		
	STATE=$S

	sleep 1
done
