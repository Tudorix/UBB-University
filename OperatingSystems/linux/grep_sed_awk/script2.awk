BEGIN{
	print "NUME PRENUME DATA SALARIU"
	total = 0
}

{
	print $0
	total += 1
}

END{
	print "Nr de angajati: ", total
}
