append([],C,C):-!.
append([],[],[]).

append([H|T],L,[H|R]):-
    append(T,L,R).

inloc([],_,_,[]).

inloc([H|T],H,V,R):-
    append(V,R1,R),
    inloc(T,H,V,R1).

inloc([H|T],K,V,[H|R]):-
    not(H =:= K),
    inloc(T,K,V,R).

elim([],_,_,[]).

elim([H|T],K,N,[H|R]):-
    K =\= N,
    K1 is K + 1,
    elim(T,K1,N,R).

elim([H|T],N,N,R):-
    N1 is N + 1,
    elim(T,N1,N,R).