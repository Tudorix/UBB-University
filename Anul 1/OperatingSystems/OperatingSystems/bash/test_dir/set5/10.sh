#!/bin/bash

for F in $@; do
	du -b $F | awk '{print $1}'
done | sort -nr 
