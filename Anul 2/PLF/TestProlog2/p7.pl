inmultire([],_,0,[]).

inmultire([H|T],C,F1,[Z|R]):-
    inmultire(T,C,F,R),
    Rez is C * H + F,
    Z is Rez mod 10,
    F1 is Rez // 10.

main(L,C,R):-
    inmultire(L,C,F,R),
    F is 0.

main(L,C,R):-
    inmultire(L,C,F,R1),
    F > 0,
    R = [F|R1].