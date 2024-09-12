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
	peek_code(end_of_file),	!.

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

main :-
    read_string(Name),
    string_chars(String, Name),
    write("Kvedja,"),
    nl,
    write(String),
    nl.
