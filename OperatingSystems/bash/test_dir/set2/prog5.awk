BEGIN {
	
}

{
	total_words += NF
	for(i = 1; i<= NF; i++){
		freq[$i]++;
	}
}

END {
	avg = total_words / NR
	print avg
	for(w in freq){
		if(freq[w] < avg){
			print w
		}
	}
}
