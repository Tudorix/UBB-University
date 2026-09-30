#!/bin/bash

for link in $(find "$1" -type l ); do
	if [ ! -e $link ]; then
		echo Dosent exist
	fi
done
