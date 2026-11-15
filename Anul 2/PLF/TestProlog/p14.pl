exista([H|T],H,T).

exista([H|T],K,[H|R]):-
    H \= K,
    exista(T,K,R).

eg([],[]).

eg([H|T],L):-
    exista(L,H,R),
    eg(T,R).

sn([],K,[]):-
    K =\= 0.

sn([H|T],0,[H]):-!.

sn([H|T],K,R):-
    K1 is K - 1,
    sn(T,K1,R).