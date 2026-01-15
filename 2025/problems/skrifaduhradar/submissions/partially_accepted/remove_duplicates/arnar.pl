[kattio].

read_list(0, []).
read_list(N, [X | Xs]) :-
    read_int(X),
    N1 is N - 1,
    read_list(N1, Xs).

calc([], _WordSum, _WPM, Res, Res).
calc([X | Xs], WordSum, WPM, SubRes, Res) :-
    WordSum2 is WordSum + X,
    Y is WordSum2 div WPM,
    SubRes2 is SubRes + Y,
    calc(Xs, WordSum2, WPM, SubRes2, Res).

binary_search(SL, Target, Lo, Hi, Best, Result) :-
    Hi < Lo
->  Result is Best
;   Mid is (Lo + Hi) div 2,
    calc(SL, 0, Mid, 0, Penalty),
(   Penalty < Target
->  (   Mid1 is Mid - 1,
        binary_search(SL, Target, Lo, Mid1, Mid, Result)
    )
;   (   Mid1 is Mid + 1,
        binary_search(SL, Target, Mid1, Hi, Best, Result)
    )
).


main :- 
    read_int(N),
    read_int(Target),
    read_list(N, L),
    sort(L, SL),
    Hi is 1000000000000000,
    binary_search(SL, Target, 1, Hi, Hi, Result),
    write(Result),
    nl.
