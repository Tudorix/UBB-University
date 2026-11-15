% app(L,L,R)

app([],L,L).

app([H|T],L,[H|R]):-
    app(T,L,R).

% sw(L,E,C,R)

sw([],_,_,[]).

sw([H|T],H,C,R1):-
    sw(T,H,C,R),
    app(C,R,R1).

sw([H|T],K,C,[H|R]):-
    K \= H,
    sw(T,K,C,R).