#!/bin/bash

for F in `find $1 -name "*.log" `; do
	sort "$F" > "$F.tmp"
	mv "$F.tmp" "$F"
	rm -f "$F.tmp"
done	
