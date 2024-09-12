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

read_list([], 0).
read_list([Item | L], N) :-
    N1 is N - 1,
    read_string(Item),
    read_list(L, N1).

write_list([]).
write_list([Item | L]) :-
    string_chars(ItemS, Item),
    write(ItemS),
    nl,
    write_list(L).

swap(Input, I, J, Output) :-
   same_length(Input, Output),
   append(BeforeI,[AtI | PastI], Input),
   append(BeforeI,[AtJ | PastI], Bs),
   append(BeforeJ,[AtJ | PastJ], Bs),
   append(BeforeJ,[AtI | PastJ], Output),
   length(BeforeI,I),
   length(BeforeJ,J).

solve(L, N, Output) :-
    Ind is 12 mod N,
    swap(L, 0, Ind, Output).

main :-
    read_int(N),
    read_list(L, N),
    solve(L, N, Output),
    write_list(Output),
    nl.
