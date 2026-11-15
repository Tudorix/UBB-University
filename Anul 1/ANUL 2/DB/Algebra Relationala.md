Relatie = colectie de tupluri unice
## Operatori
#### De Baza
- Proiectie
- Selectie
- Prod Cartezian
- Diferenta
- Reuniunea
#### Aditionali
- Join
- Intersectie
- Catul
- Redenumirea

## Proiectia
L - Lista de coloane (a1,..,an)
Returneaza o realatie eliminand toate atributele care nu sunt in L.

```
SELECT  DISTINCT a1 , a2 
FROM ...
```

## Selectie
Selecteaza tuplurile unei relatii R car verifica o conditie
```
SELECT ... FROM ... 
WHERE <condition>
```

### ==🔴!! Proiectia poate eleimina campuri dintr-o selectie !!==

## Reuniune
```
SELECT DISTINCT *
FROM R1
UNION
SELECT DISTINCT *
FROM R2
```
# ==🟣!!! Se compara MULTIMI==

## Itersectie
```
SELECT DISTINCT *
FROM R1
INTERSECT
SELECT DISTINCT *
FROM R2
```

## Diferenta
```
SELECT DISTINCT *
FROM R1
EXCEPT
SELECT DISTINCT *
FROM R2
```

## Prod Cartezian
```
SELECT DISTINCT * 
FROM R1, R2
```

#### Equi-Join 
Nu se dubleaza ==🟡campul comun==

## Catul

Deci practic, daca ai 2 tabele cu o tabela de legatura, Catul returneaza
campurile din R1 care sunt in relatie cu toate val din R2

