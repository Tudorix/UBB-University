```
Stream Line Editor

Daca nu specifici un nr de linie comanda se va aplica pt toate

Comenzi:
-n - ca sa nu afisese bufferul intern de prelucrare
-r - extended regular expression

'' <filename> - afiseaza tot fisierul
-n 'p' <filename> - afis tot fisierul

-n '5,10p' <fn> - afis de la linia 5 la linia 10
-n '8,$p' <fn> - de la ln. 8 pana la final

sed -n '/Tudor/p' anagajati.txt - liniile pe care apare 'Tudor'

sed -E "/regex/d" a.txt - stergere la toate liniile
sed -E "y/characters/replacement/" a.txt - map replacement

sed -n 'w angajati.bak' angajati.txt 

sed '$ a TERMINAT' angajati.txt 

sed '2 c SALARIAT PENSIONAT' angajati.txt 

sed '3 r text.txt' angajati.txt 

sed '3 a Linie Adaugata' angajati.txt 
sed '/Adrian/a Despot!!' angajati.txt 

sed -E "s/regex/replacement/flags" a.txt - inlocuieste regex uri

\t = tab

	The flags at the end can be g, i, or both
	1. g - Perform the replacement everywhere on the line. Without it, only the first appearance
	will be replaced
	2. i - Perform a case-insensitive search
	v. The replacement can contain reference to the expressions grouped in the regex as \1, \2, etc, the
	number being the order in which the groups appear in the regex
	
Ca sa stergi cuvnite dintr-un rand folosesti substitute si inlocuiesti cu ''
Fara 'g' se aplica doar primei aparitii la substitute

Poti pune orice simbol in loc de '/', de ex '@'
& - scrie regexul : sed 'sed/Tudor/&el/' -> inlocuieste cu 'Tudorel'
```