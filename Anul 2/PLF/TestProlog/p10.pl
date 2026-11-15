inter([],_,_,[]).
inter(T,-1,_,T).

inter([H|T],N,E,[H|R]):-
    N > 0,
    N1 is N - 1,
    inter(T,N1,E,R).

inter([H|T],N,E,[E,H|R]):-
    N =:= 0,
    N1 is N - 1,
    inter(T,N1,E,R).

cmmdc(A,A,A):-!.

cmmdc(A,B,R):-
    A > B,
    A1 is A - B,
    cmmdc(A1,B,R).

cmmdc(A,B,R):-
    B > A,
    B1 is B - A,
    cmmdc(A,B1,R).

lista([],H,H).

lista([H|T],K,R):-
    cmmdc(K,H,L),
    lista(T,L,R).

cmdl([H|T],R):- lista(T,H,R).

