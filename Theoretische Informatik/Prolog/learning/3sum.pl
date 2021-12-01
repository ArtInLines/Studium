% Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

conc([],L,L).
conc([X|R], L, [X|RL]) :- conc(R, L, RL).


rmDuplicates([],[]).
rmDuplicates([[X,Y,Z]|R],R) :- member([X,Y,Z],R).
rmDuplicates([[X,Y,Z]|R],[[X,Y,Z]|Res]) :- rmDuplicates(R,Res).


findSummand(_,[],[]).
findSummand(X,[H|_],H) :- 0 =:= X+H.
findSummand(X,[_|T],Y) :- findSummand(X,T,Y).


threeSum([],[]).
threeSum([_|[]],[]).
threeSum([_,_|[]],[]).
threeSum([H,X|T],[[H,X,Summand]|Res]) :- TwoSum is H + X, 
                                    findSummand(TwoSum,T,Summand), 
                                    Summand \= [], threeSum([H|T],R1), 
                                    threeSum([X|T],R2), 
                                    conc(R1,R2,R),
                                    rmDuplicates(R,Res).
threeSum([H,_|T],Res) :- threeSum([H|T],Res), Res \= [].
threeSum([_,X|T],Res) :- threeSum([X|T],Res).