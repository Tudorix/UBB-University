% replace(L - list,O - element,N - elemnt,Result - lista)
% L - lista initiala
% O - elementul care trebuie inlocuit
% N - noua valoare a elemntului inlocuit
% Result - lista rezultata dupa inlocuire
% Model de flux : (i,i,i,o)

replace([],_,_,[]).
replace([H|T],X,Y,[Z|R]):-
    H = X,
    Z = Y,
    replace(T,X,Y,R).
replace([H|T],X,Y,[Z|R]):-
    H \= X,
    Z = H,
    replace(T,X,Y,R).