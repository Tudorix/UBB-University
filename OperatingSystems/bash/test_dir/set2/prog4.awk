BEGIN {
	max = -1
	min = 10

	i_max = 0
	i_min = 0
}

{
	if(NF > max){
		max = NF
		i_max = $0
	}

	if(NF < min){
		min = NF
		i_min = $0
	}
}

END {
	print i_min
	print i_max
}
