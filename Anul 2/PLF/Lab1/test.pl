male(harry).
feamle(liz).
feamle(mary).

parent(phil, chas).
parent(liz,chas).
parent(liz,mary).

parent(chas,harry).
parent(chas,wills).
parent(chas,anabelle).

grandmother(GM,C):-
    mother(GM,P),
    parent(P,C).

mother(M,C):-
    feamle(M),
    parent(M,C).

siblings(F1,F2):-
    parent(P,F1),
    parent(P,F2).

siblings(F1,F2,F3):-
    parent(P,F1),
    parent(P,F2),
    parent(P,F3).

aunt(A,N):-
    feamle(A),
    siblings(A,E),
    parent(E,N).