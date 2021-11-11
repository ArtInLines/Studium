conc([],L,L).
conc([X|R], L, [X|RL]) :- conc(R, L, RL).

zipper([],L,L).
zipper(L,[],L).
zipper([X|R],[Y|S],[X,Y|T]) :- zipper(R,S,T).