```
test - functie de evaluare a exp. logice (de citit falguri)

A = 5 - se creeaza variabile A = 5
B = ion
echo $A - valoarea lui A
echo $A ${B}i -> 5 ioni

C=`./main sys < a.txt` - se stocheaza in C outputul comenzii
echo "$C" - ignora prop. de wildcard a caracterlui '*'

wc - word count
ls | wc -l - nr de linii

d rwx rwx rwx -> Permisiunile unui fisier
tipul: dir. | fisier
permisiunile userului - grupului - other

i.e.:
-rw-rw-r-- 1 tudorix tudorix    42 mar  4 09:06 a.txt
tip - fisier
grupul(1) - tudorix
ownerul(2) - tudorix

chmod - schimbare de permisiuni a unui fisier
- primeste un nr in baza 8 (abc - permisiunile)
  
-la inceput de fisier bash #! /bin/bash - ruleaza cu bash (paote cu C , python, etc)

$0 - numele comenzii
$1 - primul argument
$* - toate argumentele
$@ - 
$# - 

shift 3 - shiftare argumente

--- FOR ---

for A in lista_de_chestii; do
	echo $A
done

lista_de_chestii -> valori, comanda shell

--- IF ---

if test <ceva>; then
	//ceva
elif test <altceva>; then
	//altceva
else
	//else
fi

--- WHILE ---

while <comnda>; do
	//face ceva(sper)
done
 
```