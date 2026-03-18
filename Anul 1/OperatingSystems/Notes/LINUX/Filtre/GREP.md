```
./ - current working path
. - current directory

##### FILTRE #####

---Filtre---
Grep , Sed , Awk - filtre linux
sort | uniq

#### GREP #####

. - match pe orice caracter (* joat)
\. - cauta un punct
[abc] - un singur caracter aflat in paranteza (a,b sau c)
[^abc] - un singur caracter care NU e in paranteza
[A-Z] - litera mare
[a-z] - litera mica
[a-zA-Z] - orice liteara
[0-9] - cifra
[^0-9] - nu e cifra
\d - o cifra
\s - un caracter special
\w - caracter sau "_"
() - grupare a mai multor caractere intr-o expresie

-q -> nu scrie outputul

---Ancore---
!!! o linie incepe(in procesor) cu ^ si se termina cu $

^a - prima litera e a
a$ - ultima litera e a

\<Garbor\> - match exact pe sirul 'Gabor' ,  fara prefix sau sufix

---Repetitii---
a{5}b - match = aaaaab
? - cel mult o data
* - zero sau mai multe
+ - 1 sau mai multe
{n} - exact n ori
{n,} - n sau mai multe ori
{,m} - cel mult m ori
{n,m} - cel putin n, cel mult  m

Extended Regular Expressions (ERE) - un mod pt. grep (-E)
In BRE toate caracterele speciale trebuie prefixate cu '\'

---Flags---
-c - numarul de linii 
-i - ignora diferenta la Case Sensitiveness
-v - liniile care NU sunt match
-e - regular expression
-f FILE - preia o expresie regualra din fisierul FILE

-m 1 - prima aparitie
-o - printeaza doar partea de match

-A 2 - 2 linii deasupra(Above)
-B 2 - 2 linii dedesupt(Below)

##### AWK #####

awk - pattern recognition
awk -f<simbol> - pr dupa un simbol

##### SED #####

-E - ERE mode

- are 2 buffere - cel de IO si bufferul lui de editare (dubleaza la printare in BRE)
  
$p - ultima linie

##### SORT #####

sort - sorteaza alfabetic
sort -n - numeric
sort -r - reverse

##### HEAD #####

head -n 20 - primele 20 de intrari

##### UNIQ #####

uniq - elimina repetitile
uniq -c - cate se repeta

grep -E -i 'aeiou' -o | wc -l

```