del_at([],_,[]).

del_at([H|T],H,R):-
    del_at(T,H,R).

del_at([H|T],K,[H|R]):-
    not(H = K),
    del_at(T,K,R).

exista([H|T],H):-!.
exista([H|T],K):-
    not(K = H),
    exista(T,K).

% nr_ap(L,C,R)

numara([],_,0).

numara([H|T],H,R):-
    numara(T,H,R1),
    R is R1 + 1.

numara([H|T],E,R):-
    not(H = E),
    numara(T,E,R).

nr_ap([],[],_).

nr_ap([H|T],[[N,H]|R],C):-
    numara([H|T],H,N),
    not(exista(C,H)),
    nr_ap(T,R,[H|C]).

nr_ap([H|T],R,C):-
    exista(C,H),
    nr_ap(T,R,C).

