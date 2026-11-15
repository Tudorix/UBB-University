% div(N,K,Rez).

div(N,1,[]):-!.

div(N,K,[K|Rez]):-
    N mod K =:= 0,
    K1 is K - 1,
    div(N,K1,Rez).

div(N,K,Rez):-
    N mod K =\= 0,
    K1 is K - 1,
    div(N,K1,Rez).

d(N,R):- 
    N > 3,
    div(N,N - 1,R).

d(N,[]):- N < 4.

% app(L,R,Rez)

app([],C,C).

app([H|T],R,[H|Rez]):-
    app(T,R,Rez).

lista([],[]):-
    write("Here").

lista([H|T],R1):-
    lista(T,R),
    d(H,Divs),
    app([H|Divs],R,R1).
