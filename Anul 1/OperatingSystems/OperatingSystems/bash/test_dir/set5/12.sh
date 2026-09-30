#!/bin/bash

state="$(ls $1)"
while true; do
	verif="$(ls $1)"
	if ! [ "$state" == "$verif" ];then
		echo Changed
		state=$verif
	fi
	sleep 1
done
