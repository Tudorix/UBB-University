% sublist(L - lista, M - numar, N - numar ,Result - lista, I - numar)    
% L - lista initiala
% M - indicele primei pozitii
% N - indicele ultimei pozitii
% Result - sublista rezultata
% I - indicele curent
% Model de flux : (i,i,i,o,i)

sublist([],_,_,[],_).
sublist([H|T],M,N,[X|Y],I):-
    I >= M,
    I =< N,
    X = H,
    I1 is 1 + I,
    sublist(T,M,N,Y,I1).
sublist([H|T],M,N,Y,I):-
    (I < M; I > N),
    I1 is 1 + I,
    sublist(T,M,N,Y,I1).

sublist_main(L,M,N,I) = sublist(L,M,N,I,1)