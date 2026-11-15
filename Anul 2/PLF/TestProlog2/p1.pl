% suma(l1,l2,R)

z(L,0,L):-!.

z(L,N,[0|R]):-
    N1 is N - 1,
    z(L,N1,R).

ln([],R,R).

ln([H|T],Z,R):-
    Z1 is Z + 1,
    ln(T,Z1,R).

eq(L1,L2,R1,R2):-
    ln(L1,0,Len1),
    ln(L2,0,Len2),
    Len1 > Len2,
    Dif is Len1 - Len2,
    R1 = L1,
    z(L2,Dif,R2).

eq(L1,L2,R1,R2):-
    ln(L1,0,Len1),
    ln(L2,0,Len2),
    Len1 < Len2,
    Dif is Len2 - Len1,
    R2 = L2,
    z(L1,Dif,R1).

eq(L1,L2,R1,R2):-
    ln(L1,0,Len1),
    ln(L2,0,Len2),
    Len1 =:= Len2,
    R2 = L2,
    R1 = L1.


suma([],[],0,[]).

suma([H1|T1],[H2|T2],C1,[R1|R]):-
    suma(T1,T2,C,R),
    Z is H1 + H2 + C,
    C1 is Z // 10,
    R1 is Z mod 10.


main(L1,L2,R):-
    eq(L1,L2,C1,C2),
    suma(C1,C2,0,R).

main(L1,L2,R1):-
    eq(L1,L2,C1,C2),
    suma(C1,C2,C,R),
    C is 1,
    R1 = [1|R].

lista([],C,C).

lista([H|T],C,R):-
    is_list(H),
    main(H,C,C1),
    lista(T,C1,R).

lista([H|T],C,R):-
    \+ is_list(H),
    lista(T,C,R).