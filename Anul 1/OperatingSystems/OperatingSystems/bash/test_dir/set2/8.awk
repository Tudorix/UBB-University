BEGIN {
	k = 0
}

{
	print $1, $2
	print ($3 + $4 + $5) / 3
	if(($3 + $4 + $5) / 3 > 8){
		freq[k] = $1 " " $2
		k++
	}
}

END {
	for(w in freq){
		print freq[w]	
	}
}
