BEGIN {
	sum = 0
	c = 0
}

{
	if(NF % 2 == 0){
		print $1 + $NF
	}

	for(i = 1; i <= NF; i++){
		if(NR % 2 == 1 && i == int(NF / 2)){
			sum += $i
			c++
		}
	}
}

END {
	print sum / c
}
