% A 

cmmdc(L,L,L):-!.

cmmdc(A,B,R):-
    A > B,
    A1 is A - B,
    cmmdc(A1,B,R).

cmmdc(A,B,R):-
    B > A,
    B1 is B - A,
    cmmdc(A,B1,R).

cmmmc(A,B,R):-
    cmmdc(A,B,R1),
    R is (A * B) // R1.

lista([H],H).

lista([H|T],R1):-
    lista(T,R),
    cmmmc(R,H,R1).

% B
% add2(L,V,R)

add2([],_,_,_,[]).

add2([H|T],K,P,V,[H,V|R]):-
    K is P,
    P1 is P * 2,
    K1 is K + 1,
    add2(T,K1,P1,V,R).

add2([H|T],K,P,V,[H|R]):-
    not(K is P),
    K1 is K + 1,
    add2(T,K1,P,V,R).