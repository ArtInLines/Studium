conc([],L,L).
conc([X|R], L, [X|RL]) :- conc(R, L, RL).


zipper([],L,L).
zipper(L,[],L).
zipper([X|R],[Y|S],[X,Y|T]) :- zipper(R,S,T).


rev([],[]).
rev([X|R],L) :- rev(R,S), conc(S,[X],L).


pali([],[]).
pali([X],[X]).
pali([X|R],[X|T]) :- pali(R,P), conc(P,[X],T).


split([],_,[],[]).
% split([],_,G,K) :- G,K.
split([E|R],E,K,G) :- split(R,E,K,G).
split([X|R],E,K,G) :- X<E, conc(K,[X],L), split(R,E,L,G).
split([X|R],E,K,G) :- X>E, conc(G,[X],L), split(R,E,K,L).


% split([A|Rest], A, [A|Rest1], Rest2) :-
%         split(Rest, A, Rest1, Rest2).
% split([A|Rest], B, Rest1, [A|Rest2]) :-
%         A =\= B,
%         split(Rest, B, Rest1, Rest2).

% split([H|T],E,K,G) :- >(H,E), conc(G,[H],L), split(T,E,K,L).
% split([H|T],E,K,G) :- <(H,E), conc(K,[H],L), split(T,E,L,G).
% split([H|T],E,K,G) :- =(H,E), conc(K,[H],L), split(T,E,L,G).