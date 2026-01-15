[kattio].

main :- 
    read_int(N), read_int(M),
    (   not(dif(N, M))
    ->  write("Dufur passa fullkomlega\n")
    ;   N < M
    ->  write("Dufur passa\n")
    ;   write("Dufur passa ekki\n")
    ).
