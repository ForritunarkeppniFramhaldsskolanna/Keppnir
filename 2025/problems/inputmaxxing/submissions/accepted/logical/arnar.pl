[kattio].

read_list(0, []).
read_list(N, [X | Xs]) :-
    read_int(X),
    N1 is N-1,
    read_list(N1, Xs).

main :- 
    read_int(N),
    read_list(N, L),
    max_list([N | L], M),
    write(M),
    nl.
