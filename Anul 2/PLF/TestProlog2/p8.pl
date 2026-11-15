% add(L,F,R).

add([9],1,[0]).
add([E],0,[E1]):-
    E < 9,
    E1 is E + 1.

add([H|T],F1,[Z|R]):-
    add(T,F,R),
    F > 0,
    Rez is H + F,
    Z is Rez mod 10,
    F1 is Rez // 10.

add([H|T],F,[H|R]):-
    add(T,F,R),
    F is 0.

ma(L,R):-
    add(L,F,R),
    F =:= 0.

ma(L,R):-
    add(L,F,R1),
    F > 0,
    R = [1|R1].

