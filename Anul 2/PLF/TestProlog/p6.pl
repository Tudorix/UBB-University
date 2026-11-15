
numara([],_,0):-!.

numara([H|T],H,R):-
    numara(T,H,R1),
    R is R1 + 1.

numara([H|T],K,R):-
    H \= K,
    numara(T,K,R).

elim_dup([],_,[]).

elim_dup([H|T],C,[H|R]):-
    numara(T,H,R1),
    R1 =:= 0,
    numara(C,H,R2),
    R2 =:= 0,
    elim_dup(T,C,R).

elim_dup([H|T],C,R):-
    numara(T,H,R1),
    R1 =:= 0,
    numara(C,H,R2),
    R2 > 0,
    elim_dup(T,C,R).

elim_dup([H|T],C,R):-
    numara(T,H,R1),
    R1 > 0,
    elim_dup(T,[H|C],R).


me([H],H):-!.

me([H|T],H):-
    me(T,R1),
    H > R1.

me([H|T],R1):-
    me(T,R1),
    H < R1.

elim([],[],_):-!.

elim([H|T],[H|R],K):-
    H \= K,
    elim(T,R,K).

elim([H|T],R,K):-
    H = K,
    elim(T,R,K).
