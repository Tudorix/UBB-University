repl([],_,_,[]).

repl([H|T],H,E,[E|R]):-
    repl(T,H,E,R).

repl([H|T],K,E,[H|R]):-
    H \= K,
    repl(T,K,E,R).

subl([],_,_,_,[]).
subl([],_,M,N,[]):-
    M > N.

subl([H|T],K,M,N,[H|R]):-
    K >= M,
    K =< N,
    K1 is K + 1,
    subl(T,K1,M,N,R).

subl([H|T],K,M,N,R):-
    K < M,
    K1 is K + 1,
    subl(T,K1,M,N,R).

subl([H|T],K,M,N,R):-
    K > N,
    K1 is K + 1,
    subl(T,K1,M,N,R).
