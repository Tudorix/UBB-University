```
In linux totul e un fisier

Linia de comanda = descriptor de fisier

find - cautare de fisier

open() - return int -> file descrpitor
0 - stdin
1 - stdout
2 - stderr

ls 2 >> a.txt - >>(concat) ; 2 - stderr
./main sys < a.txt > b.txt

/dev/null - ca sa ascunzi outputul
2 > &1 - errorile merge in adersa lui 1(stdout) : find /etc > /dev/null 2 > &1

echo $? - codul de iesire al exe. programului anterior

lazy evaluation - se evalueaza o conditie pana cand are sens
(i.e. true || ls - ls NU se ruleaza pt ca true || - e mereu true) 
```