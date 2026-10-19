from itertools import permutations, combinations # Fac permutari/ combinari
from random import sample
from math import factorial, perm, comb # Dau nr lor
from itertools import combinations_with_replacement

# --- PB 1 ---

a = "randomise"

# a
lista_permutari = list(permutations(a))
print(lista_permutari[:13])

# b
NrPermutari = factorial(len(a))
print(NrPermutari)

# c
PermAleatoare = sample(a,len(a))
print(PermAleatoare)

# --- PB 2 ---

def aranjamente(s,n, nr_total = False, aleator = False):
    if nr_total:
        return perm(len(s), n)
    
    if aleator:
        return sample(s,n);

    return list(permutations(s,n))

def combinari(s,n, nr_total = False, aleator = False):
    if nr_total:
        return comb(len(s), n)
    
    if aleator:
        return sample(s,n);

    return list(combinations(s,n))

print(aranjamente('word',2))
print(aranjamente('word',2, nr_total=True))
print(aranjamente('word',2, aleator=True))

print(combinari('word',2))
print(combinari('word',2,nr_total=True))
print(combinari('word',2,aleator=True))

# --- PB 3 ---

sortim = ['Ananas','Ciocolata','Fistic','Kiwi','Mango','Vanilie','Zmeura']

print(list(combinations_with_replacement(sortim,3)))
print(comb(len(sortim) + 3 - 1,3))
