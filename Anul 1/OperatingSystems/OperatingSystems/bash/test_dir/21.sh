#!/bin/bash

last | awk '{print $1}' | sort | uniq | while read -r Name; do
	if [ "$Name" != "" ];then
		echo $Name
		touch $Name
		last | grep -E "$Name" > $Name
	fi
done
