p(N,N).

p(N,K):-
    \+ N mod K =:= 0,
    K1 is K + 1,
    p(N,K1).  

prim(N):-
    N > 1,
    p(N,2).

lista([],[]).

lista([H|T],[H,H|R]):-
    prim(H),
    lista(T,R).


lista([H|T],[H|R]):-
    \+ prim(H),
    lista(T,R).