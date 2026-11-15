rev([],C,C).

rev([H|T],C,R):-
    rev(T,[H|C],R).

cons([],_,_,Mlist,_,_,R1):-
    rev(Mlist,[],R1).

cons([H|T],0,M,Mlist,C,Clist,Rez):-
    H mod 2 =:= 0,
    C1 is C + 1,
    C1 >= M,
    Clist1 = [H|Clist],
    cons(T,1,C1,Clist1,C1,Clist1,Rez).

cons([H|T],1,M,Mlist,C,Clist,Rez):-
    H mod 2 =:= 0,
    C1 is C + 1,
    C1 >= M,
    Clist1 = [H|Clist],
    cons(T,1,C1,Clist1,C1,Clist1,Rez).

cons([H|T],1,M,Mlist,C,Clist,Rez):-
    H mod 2 =:= 0,
    C1 is C + 1,
    C1 < M,
    cons(T,1,M,Mlist,C1,[H|Clist],Rez).

cons([H|T],0,M,Mlist,C,Clist,Rez):-
    H mod 2 =:= 0,
    C1 is C + 1,
    C1 < M,
    cons(T,1,M,Mlist,C1,[H|Clist],Rez).

cons([H|T],_,M,Mlist,C,Clist,Rez):-
    H mod 2 =\= 0,
    cons(T,0,M,Mlist,0,[],Rez).

