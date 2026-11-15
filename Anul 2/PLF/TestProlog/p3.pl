este([H|T],H):-!.

este([H|T],R):-
    este(T,R).

multime([],[],_).

multime([H|T],[H|R],C):-
    not(este(C,H)),
    multime(T,R,[H|C]).

multime([H|T],R,C):-
    este(C,H),
    multime(T,R,C).


pare_impare([],[[],[]]).

pare_impare([H|T],[[H|P],I]):-
    H mod 2 =:= 0,
    pare_impare(T,[P,I]).

pare_impare([H|T],[P,[H|I]]):-
    H mod 2 =:= 1,
    pare_impare(T,[P,I]).
