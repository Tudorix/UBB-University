% pred(L1 - lista numere, O - numar, L2 - lista numere)
% L1 - lista initiala de numere
% O - numarul ce indica overflow
% L2 - lista de numere output
% model ed flux (i,i,o)

pred([0],1,[9]).
pred([H],0,[X]):-
    H > 0,
    X is H - 1.

pred([H|T],1,Y):-
    pred(T,O1,Z),
    H = 0,
    C1 = 9,
    O1 = 1,
    Y = [C1|Z].

pred([H|T],O,Y):-
    pred(T,1,Z),
    H > 0,
    C1 is H - 1,
    O = 0,
    Y = [C1|Z],!.

pred([H|T],0,Y):-
    pred(T,0,Z),
    Y = [H|Z].

pred_main(L1,L2):- pred(L1,0,L2).

% -----------------------------------------------------------------------------


% pred_lista(L1 - lista, L2 - lista).
% L1 - lista de input
% L2 - lista de output
% model de flux (i,o)

pred_lista([],[]).

pred_lista([H|T],Y):-
    pred_lista(T,Z),
    is_list(H),
    pred_main(H,R),
    Y = [R|Z].

pred_lista([H|T],Y):-
    pred_lista(T,Z),
    \+ is_list(H),
    Y = [H|Z].