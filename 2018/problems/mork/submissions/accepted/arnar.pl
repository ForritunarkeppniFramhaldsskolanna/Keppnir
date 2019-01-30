read_string(S) :-
    read_token_codes(S).

read_int(I) :-
    read_token_codes(Codes),
    (Codes == end_of_file -> I = Codes ; number_codes(I, Codes)).

read_atom(A) :-
    read_token_codes(Codes),
    (Codes == end_of_file -> A = Codes ; atom_codes(A, Codes)).


% Internal predicate for getting the next token

read_token_codes(end_of_file) :-
    peek_code(end_of_file), !.

read_token_codes(Codes) :-
    peek_code(C),
    \+ code_type(C, space), !,
    read_token_codes_helper(Codes).

read_token_codes(T) :-
    get_char(_), !,
    read_token_codes(T).


read_token_codes_helper([C0|C]) :-
    peek_code(C0),
    \+ code_type(C0, space), !,
    get_code(C0),
    read_token_codes_helper(C).

read_token_codes_helper([]).

other(N) :- dif(N,2), dif(N,0).

cond(N,M) :- dif(N,M).
cond(N,M) :- other(N), other(M).

solve(0,0) :- write("Jebb"),!.
solve(2,2) :- write("Jebb"),!.
solve(N,M) :- write("Neibb").

main :-
    read_int(N), read_int(M),
    (N == end_of_file; M == end_of_file;
        solve(N,M), nl, fail
    ).
