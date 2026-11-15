% A
este([H|T],H):-!.
este([H|T],E):-
    este(T,E).

diferenta([],_,[]).

diferenta([E|L1],L2,[E|R]):-
    not(este(L2,E)),
    diferenta(L1,L2,R).

diferenta([E|L1],L2,R):-
    este(L2,E),
    diferenta(L1,L2,R).

% B
% add1(L,R)

add1([],[]):-!.

add1([H|T],R):-
    H mod 2 =:= 0,
    R = [H,1|R1],
    add1(T,R1).

add1([H|T],[H|R]):-
    not(H mod 2 =:= 0),
    add1(T,R).
