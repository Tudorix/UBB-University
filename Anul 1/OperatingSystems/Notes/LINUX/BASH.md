```
-pinky

-find . -type f - gaseste fisiere intr-un director

"" - substitutie
'' - text asa-cum-e

  
-la inceput de fisier bash #! /bin/bash - ruleaza cu bash (paote cu C , python, etc)

$0 - numele comenzii
$1 - primul argument
$* - toate argumentele
$@ - lista argumente
$# - lista argumente
$? - exit code

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
 
 
expr pt numere
```