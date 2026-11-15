% prd(L,F,R)

prd([0],1,[9]):-!.
prd([E],0,[E1]):-
    E1 is E - 1,!.

prd([0|T],F1,[Z|R]):-
    prd(T,F,R),
    F =:= 1,
    Z is 9,
    F1 is 1.

prd([H|T],F1,[Z|R]):-
    prd(T,F,R),
    F =:= 1,
    Z is H - 1,
    F1 is 0,!.

prd([H|T],F,[H|R]):-
    prd(T,F,R),
    F =:= 0.