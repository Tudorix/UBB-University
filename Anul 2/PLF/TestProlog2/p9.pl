    consec([H],_,[H]).
    
    consec([H1,H2],_,[]):-
        H1 =:= H2 - 1.

    consec([H1,H2],1,[H2]):-
        H1 =\= H2 - 1.

    consec([H1,H2],0,[H1,H2]):-
        H1 =\= H2 - 1.

    consec([H1,H2|T],_,R):-
        H1 =:= H2 - 1,
        consec([H2|T],1,R).

    consec([H1,H2|T],0,[H1|R]):-
        H1 =\= H2 - 1,
        consec([H2|T],0,R).

    consec([H1,H2|T],1,R):-
        H1 =\= H2 - 1,
        consec([H2|T],0,R).
    