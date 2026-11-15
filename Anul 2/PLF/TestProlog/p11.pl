vale([],_,2).

vale([H|T],P,0):-
    H < P,
    vale(T,H,1).

vale([H|T],P,1):-
    H < P,
    vale(T,H,1).

vale([H|T],P,1):-
    H > P,
    vale(T,H,2).

vale([H|T],P,2):-
    H > P,
    vale(T,H,2).

main([H|T]):-vale(T,H,0).

start([H|T],R):- sa(T,0,H,R).

sa([],_,S,S).

sa([H|T],1,S,R):-
    S1 is S - H,
    sa(T,0,S1,R).

sa([H|T],0,S,R):-
    S1 is S + H,
    sa(T,1,S1,R).