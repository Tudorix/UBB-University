#!/bin/bash

if ! [ -d $1 ];then
	echo Nu e dir!
	exit 1
fi

for FILE in `find -perm 755`;do
	echo $FILE
	echo Change permissions?
	read
	chmod 744 $FILE
done
