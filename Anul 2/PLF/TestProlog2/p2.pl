elim([],_,[]).

elim([H|T],H,T):-!.

elim([H|T],K,[H|R]):-
    H \= K,
    elim(T,K,R).

mini([],R,R).

mini([H|T],K,R):-
    K > H,
    mini(T,H,R).

mini([H|T],K,R):-
    K =< H,
    mini(T,K,R).

main_min([H|T],R):-mini(T,H,R).

sorti([],[]).

sorti(L,[C1|R]):-
    main_min(L,C1),
    write(C1),
    elim(L,C1,RI),
    write(RI),
    sorti(RI,R).

lista([],[]).

lista([H|T],[C|R]):-
    is_list(H),
    sorti(H,C),
    lista(T,R).

lista([H|T],[H|R]):-
    \+ is_list(H),
    lista(T,R).