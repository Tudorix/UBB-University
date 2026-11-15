exista([H|T],H):-!.

exista([H|T],K):-
    H \= K,
    exista(T,K).

inter([],_,[]).

inter([H|T],L,[H|R]):-
    exista(L,H),
    inter(T,L,R).

inter([H|T],L,R):-
    \+ exista(L,H),
    inter(T,L,R).

lista(K,N,[]):-
    K > N.

lista(M,N,[M|R]):-
    M =< N,
    M1 is M + 1,
    lista(M1,N,R).