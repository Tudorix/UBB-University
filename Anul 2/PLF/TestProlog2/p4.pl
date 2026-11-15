% it(L1,L2,R)

it([],[],[]).
it([],T,T).
it(T,[],T).

it([H|T],[H1|T1],[H|R]):-
    H =< H1,
    it(T,[H1|T1],R).

it([H|T],[H1|T1],[H1|R]):-
    H > H1,
    it([H|T],T1,R).

% dup(L,R).

dup([H1,H2],[H2]):-
    H1 =:= H2.

dup([H1,H2],[H1,H2]):-
    H1 =\= H2.

dup([H1,H2|T],[H1|R]):-
    H1 =\= H2,
    dup([H2|T],R).

dup([H1,H2|T],R):-
    H1 =:= H2,
    dup([H2|T],R).

main(L1,L2,R):-
    it(L1,L2,R1),
    dup(R1,R).