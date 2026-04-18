#!/bin/bash

for NAME in `grep -Eo '^[^ ]* ' /home/tudorix/UBB/UBB-University/OperatingSystems/bash/test_dir/who_fake`; do
	nr=`grep -E "^($NAME)" /home/tudorix/UBB/UBB-University/OperatingSystems/bash/test_dir/ps_fake | wc -l`
	echo $NAME , $nr
done

