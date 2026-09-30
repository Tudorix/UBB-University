{
	for(i = 1; i <= NF; i++){
		freq[$i]++;
	}
}

END {
	for(w in freq){
		print freq[w]
	}
}
