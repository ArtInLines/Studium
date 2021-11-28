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
% split([E|R],E,K,G) :- split(R,E,K,G).
split([X|R],E,[X|K],G) :- X=<E, split(R,E,K,G).
split([X|R],E,K,[X|G]) :- X>E, split(R,E,K,G).


qSort([],[]).
qSort([H|T],L) :- split(T,H,K,G), 
            qSort(K,LS),
            qSort(G,LR),
            conc(LS,[H|LR],L).


half([],[],[]).
half([H|[]],[H],[]).
half([H,I|T],[H|L],[I|R]) :- half(T,L,R).

% Other halfing func:
% half([],[],[]).
% half([H|T],[H|K],G) :- half(T,G,K).

merge([],S,S).
merge(S,[],S).
merge([H|T],[X|R],[H|L]) :- H=<X, merge(T,[X|R],L).
merge([H|T],[X|R],[X|L]) :- merge([H|T],R,L).


mSort([],[]).
mSort([X],[X]).
mSort([H|T],X) :- half([H|T],L,R), mSort(L,LX), mSort(R,RX), merge(LX,RX,X).


oddpossum([],0).
oddpossum([X],X).
oddpossum([X,_|R],S) :- oddpossum(R,T), S is X+T.