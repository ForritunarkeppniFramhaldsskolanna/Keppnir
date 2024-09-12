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

list_noadjs([], []).
list_noadjs([Y|Xs0], [Y|Ys]) :-
   eq_list_(Y, Xs0,Xs1),
   nohead(Xs1, Y),
   list_noadjs(Xs1, Ys).

eq_list_(_, Xs,Xs).
eq_list_(Y, [Y|Xs0],Xs) :-
   eq_list_(Y, Xs0,Xs).

nohead([], _X).
nohead([X|_], Y) :-
   dif(X, Y).

main :-
    read_string(X),
    (   X == end_of_file
    ->  nl
    ;   list_noadjs(X, Y),
        string_chars(S, Y),
        write(S),
        write(" "),
        main
    ).
