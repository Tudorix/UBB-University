% replace(L - list,O - element,N - elemnt,Result - lista)
% L - lista initiala
% O - elementul care trebuie inlocuit
% N - noua valoare a elemntului inlocuit
% Result - lista rezultata dupa inlocuire
% Model de flux : (i,i,i,o)

replace([],[]).
replace([H|T],[Z|R]):-
    Z is H * 2,
    replace(T,R).