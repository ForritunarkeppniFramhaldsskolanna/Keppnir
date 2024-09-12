% Prolog predicates for tokenized reading from stdin.
%
% Provides the following predicates:
% read_string(S): reads a string token
% read_int(I): reads an integer token
% read_atom(A): reads an atom
%
% For all three predicates, the result is unified with end_of_file
% if the end of the input stream was reached.
%

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

solve(0, Result, Result, _, _).
solve(N, Result, Running, Mul, Consecutive) :-
    read_int(Current),
    N1 is N - 1,
    UpConsecutive is Consecutive + 1,
    UpMul is min(8, 2 * Mul),
    DownMul is max(1, Mul div 2),
(   Current = 0
->  solve(N1, Result, Running, DownMul, 0)
;   UpMul = UpConsecutive
->  NewRunning is Running + UpMul * Current,
    solve(N1, Result, NewRunning, UpMul, 0)
;   NewRunning is Running + Mul * Current,
    solve(N1, Result, NewRunning, Mul, UpConsecutive)
).

solve(N, Result) :-
    solve(N, Result, 0, 1, 0).

main :-
    read_int(N),
    solve(N, Result),
    write(Result),
    nl.
