[kattio].

query(A, B) :-
    write(A),
    write(" "),
    write(B), 
    nl,
    read_string(Chars),
    string_chars(Response, Chars),
    Response =@= "Ljos!".

solve(2, 0) :-
    query(1, 2).

solve(4, 0) :-
    query(1, 2)
;   query(1, 3)
;   query(1, 4)
;   query(2, 3)
;   query(2, 4)
;   query(3, 4)
.

solve(N, I) :-
    I1 is I + 1,
    I2 is I + 2,
    I3 is I + 3,
    (   I < 6
    ->  (   query(I1, I2)
        ;   query(I1, I3)
        ;   query(I2, I3)
        ;   solve(N, I3)
        )
    ;   query(I1, I2)
    ;   solve(N, I2)
    ).

main :-
    read_int(N),
    solve(N, 0).
