exista([H|T],H).

exista([H|T],K):-
    H \= K,
    exista(T,K).

mult([],_,[]).

mult([H|T],C,[H|R]):-
    not(exista(T,H)),
    mult(T,[H|C],R).

mult([H|T],C,R):-
    exista(T,H),
    mult(T,C,R).

cmmdc(A,A,A).

cmmdc(A,B,R):-
    A > B,
    A1 is A - B,
    cmmdc(A1,B,R).


cmmdc(A,B,R):-
    A < B,
    B1 is B - A,
    cmmdc(A,B1,R).

cmdl([],K,K).

cmdl([H|T],K,R):-
    cmmdc(H,K,R1),
    cmdl(T,R1,R).

main([H|T],R):- cmdl(T,H,R).
