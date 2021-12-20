zipper([],L,L).
zipper(L,[],L).
zipper([X|R],[Y|S],[X,Y|T]) :- zipper(R,S,T).


rev([],[]).
rev([X|R],L) :- rev(R,S), conc(S,[X],L).


pali([],[]).
pali([X],[X]).
pali([X|R],[X|T]) :- pali(R,P), conc(P,[X],T).


conc([],L,L).
conc([X|R], L, [X|RL]) :- conc(R, L, RL).

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
oddpossum([X,_|R],U) :- oddpossum(R,S), U is S+X.
oddpossum([X|[]],X).


% Define  Prolog  clauses  for  a  predicate  onlypos  that  deletes  within  a  list  of  integer  numbers  all  0`s  and  replaces  each negative number by its doubled absolute value. 
onlypos([],[]).
onlypos([0|R],T) :- onlypos(R,T).
onlypos([X|R],[P|T]) :- X<0, P is -2*X, onlypos(R,T).
onlypos([X|R],[X|T]) :- onlypos(R,T).


includes([],_,0).
includes([X|R],X,1).
includes([X|R],Y,T) :- includes(R,Y,T).