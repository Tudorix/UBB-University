BEGIN {
	print ARGC

	for(i = 1; i < ARGC; i++)
		print ARGV[i]
	
	print FILENAME
}

{
	suma += 1
}

END {
	print "Suma este: ", suma
}

