mx([],M,M):-!.

mx([H|T],K,R):-
    H > K,
    mx(T,H,R).

mx([H|T],K,R):-
    H =< K,
    mx(T,K,R).

poz([],_,_,[]).

poz([H|T],H,K,[K|R]):-
    K1 is K + 1,
    poz(T,H,K1,R).

poz([H|T],E,K,R):-
    H \= E,
    K1 is K + 1,
    poz(T,E,K1,R).

lpoz([H|T],R):-
    mx(T,H,L),
    poz([H|T],L,1,R).