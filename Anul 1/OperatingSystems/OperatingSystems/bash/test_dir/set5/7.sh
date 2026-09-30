#!/bin/bash

sum=0
for F in $(ls $1); do
	if [ -f $F ];then
		add=$(du -b $F | awk '{print $1}')
		sum=$((sum + add));	
	fi
done
echo $sum
