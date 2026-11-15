% sw(L,E,R)

sw([],_,_,[]).

sw([H|T],H,N,[N|R]):-
    sw(T,H,N,R).

sw([H|T],E,N,[H|R]):-
    H \= E,
    sw(T,E,N,R).
