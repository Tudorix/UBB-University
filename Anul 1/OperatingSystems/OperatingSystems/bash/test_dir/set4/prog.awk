BEGIN {
	s=0
}

{
	if($0 ~ /^[0-9 ]*$/ ) {
		for(i = 1; i <= NF; i++){
			s += $i
		}
	}
}

END {
	print s
}
