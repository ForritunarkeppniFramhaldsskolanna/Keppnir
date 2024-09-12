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

read_quests(0, []).
read_quests(N, [quest(Name, A, B) | Quests]) :-
    read_string(Name),
    read_int(A),
    read_int(B),
    N1 is N-1,
    read_quests(N1, Quests).

better(R, quest(_, A1, B1), quest(_, A2, B2)) :-
    (   A2 == 0 -> R = >
    ;   A1 == 0 -> R = <
    ;   A1 * B2 > A2 * B1 -> R = >
    ;   R = <
    ).

output([]).
output([quest(Name, _, _) | Quests]) :-
    string_chars(String, Name),
    write(String),
    nl,
    output(Quests).

main :-
    read_int(N),
    read_int(_),
    read_quests(N, Quests),
    predsort(better, Quests, SortedQuests),
    output(SortedQuests).
