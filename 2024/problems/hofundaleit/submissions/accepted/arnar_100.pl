[assoc].

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

read_books(0, []).
read_books(N, [book(Author, Title) | Books]) :-
    read_string(TitleComma),
    append(Title, [44], TitleComma),
    read_string(Author),
    N1 is N-1,
    read_books(N1, Books).

construct([], IndexMap, _) :-
    empty_assoc(IndexMap).
construct([book(_, Title) | Books], IndexMap, Index) :-
    Index1 is Index + 1,
    construct(Books, OtherMap, Index1),
    put_assoc(Title, OtherMap, Index, IndexMap).
construct(Books, IndexMap) :-
    construct(Books, IndexMap, 1).

process_queries(0, _).
process_queries(Q, IndexMap) :-
    read_string(Title),
(   get_assoc(Title, IndexMap, Result)
->  write(Result)
;   write(-1)
),  nl,
    Q1 is Q - 1,
    process_queries(Q1, IndexMap).

main :-
    read_int(N),
    read_int(Q),
    read_books(N, Books),
    sort(Books, SortedBooks),
    construct(SortedBooks, IndexMap),
    process_queries(Q, IndexMap).
