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

write_up_to(N, N) :-
    write(" "),
    write(N).
write_up_to(X, N) :-
    write(" "),
    write(X),
    X1 is X + 1,
    write_up_to(X1, N).

make_query(N) :-
    write("?"),
    write_up_to(1, N),
    nl.

main :-
    read_int(N),
    make_query(N),
    read_int(Response),
    Answer is Response mod N,
    write("! "),
    write(Answer),
    nl.
