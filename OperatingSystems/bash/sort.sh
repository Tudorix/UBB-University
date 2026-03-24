#!/bin/bash

for FILE in `find $1`; do
	if [ -f $FILE ]; then
		CONTENT=`cat $FILE`
		echo "$CONTENT" |  sort > $FILE
	fi
done

