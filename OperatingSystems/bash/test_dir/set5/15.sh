#!/bin/bash

for Name in $(ps -ef | awk '{print $1}' | sort | uniq); do
	count=$(ps -ef | grep -E "^$Name" -c)
	echo $Name $count
done
