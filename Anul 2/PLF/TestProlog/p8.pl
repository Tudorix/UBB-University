nr_ap([],_,0):-!.

nr_ap([H|T],H,R1):-
    nr_ap(T,H,R),
    R1 is R + 1.

nr_ap([H|T],K,R):-
    H \= K,
    nr_ap(T,K,R).

mult([],_).

mult([H|T],C):-
    nr_ap(C,H,R),
    R is 0,
    nr_ap(T,H,R1),
    R1 is 0,
    mult(T,[H|C]).

% B

del_ap([],_,[]).

del_ap([H|T],H,T):-!.

del_ap([H|T],K,[H|R]):-
    K \= H,
    del_ap(T,K,R).

del_3([],_,[]).

del_3(L,E,R):-
    del_ap(L,E,R1),
    del_ap(R1,E,R2),
    del_ap(R2,E,R).
