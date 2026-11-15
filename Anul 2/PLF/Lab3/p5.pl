% sumbul(L,N,R).
% L - lista cu elemente
% N - Nr de submultimi
% R - Rezultatul
% model de flux : (i,i,o)

submul(_,0,[]):-!.

submul([H|T],N,[H|R]):-
    N1 is N - 1,
    submul(T,N1,R).

submul([H|T],N,R):-
    submul(T,N,R).

% main(L,N,R).
% L - lista cu elemente
% N - Nr de submultimi, N > 0
% R - Rezultatul
% model de flux : (i,i,o)

main(L,N,R):- 
    N > 0,
    findall(A,submul(L,N,A),R).