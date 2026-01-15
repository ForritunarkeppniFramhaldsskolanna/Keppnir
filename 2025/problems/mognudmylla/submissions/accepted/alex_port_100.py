def get_moves(s, x_to_move, lower_cnt, upper_cnt):
    lower = "x" if x_to_move else "o"
    upper = lower.upper()
    moves = []
    for i in range(9):
        if s[i] == ".":
            if lower_cnt:
                move = s[:]
                move[i] = lower
                moves.append(move)
            if upper_cnt:
                move = s[:]
                move[i] = upper
                moves.append(move)
        elif ord(s[i]) > ord("a"):
            if upper_cnt:
                move = s[:]
                move[i] = upper
                moves.append(move)
            for j in range(9):
                if s[j] == upper:
                    move = s[:]
                    move[i] = upper
                    move[j] = "."
                    moves.append(move)
    return moves


def has_player_won(s, player_is_x):
    lower = "x" if player_is_x else "o"
    upper = "X" if player_is_x else "O"
    lines = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]
    for line in lines:
        win = True
        for pos in line:
            if s[pos] != lower and s[pos] != upper:
                win = False
                break
        if win:
            return True
    return False


def get_a_winning_move(s, player_is_x, lower_cnt, upper_cnt):
    moves = get_moves(s, player_is_x, lower_cnt, upper_cnt)
    for result in moves:
        if has_player_won(result, player_is_x):
            return result
    return []


cnt_x, cnt_X = 4, 2
cnt_o, cnt_O = 4, 2
current = ["." for _ in range(9)]


def out(s):
    print("".join(s[0:3]))
    print("".join(s[3:6]))
    print("".join(s[6:9]), flush=True)


def go(s):
    global current, cnt_x, cnt_X, cnt_o, cnt_O
    out(s)
    if s.count("x") > current.count("x"):
        cnt_x -= 1
    if s.count("X") > current.count("X"):
        cnt_X -= 1
    s1 = input().strip()
    if s1 == "Sigur!":
        exit(0)
    assert s1 != "Tap!"
    s2 = input().strip()
    s3 = input().strip()
    current = list(s1 + s2 + s3)
    if current.count("o") > s.count("o"):
        cnt_o -= 1
    if current.count("O") > s.count("O"):
        cnt_O -= 1


def try_win_in_one_move():
    global cnt_x, cnt_X
    move = get_a_winning_move(current, True, cnt_x, cnt_X)
    if move != []:
        go(move)
        return True
    return False


go(list("....x...."))
if current.count("O"):
    if current.count("x"):
        s = current[:]
        s[4] = "X"
        go(s)
    else:
        go(list("X...O...."))
else:
    if current[0] == "o":
        go(list("oX..x...."))
    elif current[2] == "o":
        go(list(".Xo.x...."))
    elif current[6] == "o":
        go(list("....x.oX."))
    elif current[8] == "o":
        go(list("....x..Xo"))
    elif current[1] == "o":
        go(list(".o.Xx...."))
    elif current[3] == "o":
        go(list(".X.ox...."))
    elif current[5] == "o":
        go(list(".X..xo..."))
    elif current[7] == "o":
        go(list("...Xx..o."))
    if current.count("O"):
        if current[4] == "O":
            s = current[:]
            s[s.index("X")] = "."
            s[s.index("o")] = "X"
            go(s)
        elif current.count("o") == 0:
            s = current[:]
            s[s.index("X")] = "."
            s[s.index("x")] = "X"
            go(s)
        else:
            if try_win_in_one_move():
                exit(0)
            else:
                s = current[:]
                if not (s.index("o") & 1):
                    s[s.index("o")] = "X"
                else:
                    if s[1] == "X" or s[3] == "X":
                        s[0] = "X"
                    if s[7] == "X":
                        s[8] = "X"
                go(s)
                assert try_win_in_one_move()
                exit(0)
    else:
        assert try_win_in_one_move()
        exit(0)

while current.count("o"):
    s = current[:]
    s[s.index("X")] = "."
    s[s.index("o")] = "X"
    go(s)

for move in get_moves(current, True, 0, 1):
    if get_a_winning_move(move, False, 1, 0) == []:
        go(move)
        break

while True:
    for move in get_moves(current, True, 0, 0):
        if get_a_winning_move(move, False, 1, 0) == []:
            go(move)
            break
