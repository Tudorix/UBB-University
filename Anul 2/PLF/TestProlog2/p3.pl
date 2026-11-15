% dup(L,R)

dup([H1,H2],[H1]):-
    H1 =:= H2.

dup([H1,H2],[H1,H2]):-
    H1 =\= H2.

dup([H1,H2|T],R):-
    H2 =:= H1,
    dup([H2|T],R).

dup([H1,H2|T],[H1|R]):-
    H2 =\= H1,
    dup([H2|T],R).

% mn(L,M,R,Rest)

mn([],R,R).

mn([H|T],K,R):-
    K > H,
    mn(T,H,R).

mn([H|T],K,R):-
    K =< H,
    mn(T,K,R).

% elim(L,E,R)

elim([],_,[]).

elim([H|T],H,R):-
    elim(T,H,R).

elim([H|T],E,[H|R]):-
    E \= H,
    elim(T,E,R).

main([H|T],R1,R2):-
    mn(T,H,R1),
    elim([H|T],R1,R2).

% sr(L,R)

sr([],[]).

sr([H|T],[C|R]):-
    mn(T,H,C),
    elim([H|T],C,R1),
    sr(R1,R).

main_sr(L,R):-
    sr(L,R1),
    dup(R1,R).
