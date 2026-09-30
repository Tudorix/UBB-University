{
	if(NF % 2 == 0){
		print $1 , $NF
	}else{
		print NF
	}
}
