[kattio].

main :-
    read_int(N), read_int(M),
    K is M - 2 * N,
    (
        Rem is K mod 2,
        Rem == 0,
        Sheep is K / 2,
        Sheep >= 0,
        Sheep =< N
    ->  write(Sheep),
        nl
    ;   write("Rong talning\n")
    ).
