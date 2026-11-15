exista([H|T],H).

exista([H|T],R):-
    R \= H,
    exista(T,R).

% reun(L1,L2,R)

reun([],[],[]):-!.

reun([H|T],L,[H|R]):-
    reun(T,L,R),
    not(exista(R,H)).

reun([H|T],L,R):-
    reun(T,L,R),
    exista(R,H).
    

reun([],[H|T],[H|R]):-
    reun([],T,R),
    not(exista(R,H)).

reun([],[H|T],R):-
    reun([],T,R),
    exista(R,H).

% B

perechi([],_,[]).

perechi([H|T],L,[[L,H]|R]):-
    perechi(T,L,R).

apd([],C,C).

apd([H|T],R,Rez):-
    apd(T,[H|R],Rez).

toate([],[]).

toate([H|T],R):-
    perechi(T,H,C),
    apd(C,R1,R),
    toate(T,R1).

