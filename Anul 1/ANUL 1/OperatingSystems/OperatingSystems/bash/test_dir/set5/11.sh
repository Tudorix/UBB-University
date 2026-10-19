#!/bin/bash

content=""
for F in $(find $1 -type f -name "*.c"); do
	add=$(grep -E 'include' $F)
	content+=$'\n'"$add"
done

echo $content
