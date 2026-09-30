BEGIN {
	sum = 0
}

{
	sum += $1

	print $1 + $(NF) + $(NF - 1)
}

END {
	print sum / NR
}
