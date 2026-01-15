[kattio].
library(fastrw).

is_corner(Height, Width, Depth, Row, Col) :-
    H1 is Height - 1,
    W1 is Width - 1,
    member(ROff, [0, H1]),
    member(COff, [0, W1]),
    (   Row =:= Depth - 1 + ROff,
        Col =:= COff
    ;   Row =:= ROff,
        Col =:= Depth - 1 + COff
    ).

is_diagonal(Height, Width, Depth, Row, Col) :-
    H1 is Height - 1,
    W1 is Width - 1,
    D1 is Depth - 1,
    member(ROff, [0, H1]),
    member(COff, [0, W1]),
    I is Depth - 1 + ROff - Row,
    between(1, D1, I),
    Col =:= COff + I.

is_vertical(Height, Width, Depth, Row, Col) :-
    H1 is Height - 1,
    W1 is Width - 1,
    D1 is Depth - 1,
    member([ROff, COff], [[0, D1], [D1, 0]]),
    I is Row - ROff,
    between(0, H1, I),
    (   Col =:= COff
    ;   Col =:= COff + W1
    ).

is_horizontal(Height, Width, Depth, Row, Col) :-
    H1 is Height - 1,
    W1 is Width - 1,
    D1 is Depth - 1,
    Row + Col >= D1,
    member([ROff, COff], [[0, D1], [D1, 0]]),
    I is Col - COff,
    between(0, W1, I),
    (   Row =:= ROff
    ;   Row =:= ROff + H1
    ).

is_many(Height, Width, Depth, Row, Col) :-
    is_diagonal(Height, Width, Depth, Row, Col),
    (   is_vertical(Height, Width, Depth, Row, Col)
    ;   is_horizontal(Height, Width, Depth, Row, Col)
    )
;   is_vertical(Height, Width, Depth, Row, Col),
    is_horizontal(Height, Width, Depth, Row, Col).


output_cell(Height, Width, Depth, Row, Col) :-
    Row + Col >= Height - 1 + Width - 1 + Depth
;   is_corner(Height, Width, Depth, Row, Col),
    write('+')
;   is_many(Height, Width, Depth, Row, Col),
    write('x')
;   is_diagonal(Height, Width, Depth, Row, Col),
    write('/')
;   is_vertical(Height, Width, Depth, Row, Col),
    write('|')
;   is_horizontal(Height, Width, Depth, Row, Col),
    write('-')
;   write(' ')
.

output_row(Height, Width, Depth, Row) :-
    WD2 is Width + Depth - 2,
    foreach(between(0, WD2, Col), output_cell(Height, Width, Depth, Row, Col)),
    write('\n').

output(Height, Width, Depth) :-
    HD2 is Height + Depth - 2,
    foreach(between(0, HD2, Row), output_row(Height, Width, Depth, Row)).

main :-
    read_int(Height),
    read_int(Width),
    read_int(Depth),
    output(Height, Width, Depth).
