#i/bin/bash

for P in `ps -ef | grep -E "^ex|^yz" | awk '{print $2}' `; do
	T = `ps -o etime $P | greo -E -v ELAPSED`
	M = `echo $T | sed -E "s/:.*//"`
	S = `echo $T | sed -E "s/.*://"`
	X = `expr $M \* 60 + $S`
	
	if test $X -gt 3600; then
		echo `kill $P`
	fi
done

