BEGIN {
	k = 0
}

{
	for(i = 1; i <= NF; i++){
		if(NF % 2 == 1){
			if(i == int(NF / 2)){
				print $i
			}
		}
	}	
	if(NF > 2){
		idx = idx " " NR
	}
}

END {
	print idx
}
