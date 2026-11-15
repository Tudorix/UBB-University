% ins(L,E,K,P,I,Rez).

ins([],_,_,_,_,[]).

ins([H|T],E,P,K,K,[H,E|Rez]):-
    P1 is P * 2,
    K1 is K + P1,
    I1 is K + 1,
    ins(T,E,P1,K1,I1,Rez).

ins([H|T],E,P,K,I,[H|Rez]):-
    I \= K,
    I1 is I + 1,
    ins(T,E,P,K,I1,Rez).