par([],0).

par([H|T],1):-
    par(T,0).

par([H|T],0):-
    par(T,1).

min([],R,R).

min([H|T],K,R):-
    H < K,
    min(T,H,R).

min([H|T],K,R):-
    H >= K,
    min(T,K,R).

sterge([],_,[]).

sterge([H|T],H,T):-!.

sterge([H|T],E,[H|R]):-
    H \= E,
    sterge(T,E,R).

dpm([H|T],Rez):-
    min(T,H,R),
    write(R),
    sterge([H|T],R,Rez).