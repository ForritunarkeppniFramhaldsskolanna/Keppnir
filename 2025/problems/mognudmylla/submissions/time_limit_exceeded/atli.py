lines = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]


def result(v):
    for i in range(8):
        iswin, isloss = True, True
        for j in range(3):
            iswin &= v[lines[i][j]] > 0
            isloss &= v[lines[i][j]] < 0
        if iswin:
            return 1
        if isloss:
            return -1
    if v[9] > 0 or v[10] > 0:
        return 0
    has_small, has_big_o = False, False
    for i in range(9):
        has_small |= abs(v[i]) == 1
        has_big_o |= v[i] == 2
    if has_small and has_big_o:
        return 0
    return -1


def flip(v):
    for i in range(9):
        v[i] = -v[i]
    v[9], v[11] = v[11], v[9]
    v[10], v[12] = v[12], v[10]


def reflect(v):
    for i in range(3):
        v[i], v[i + 6] = v[i + 6], v[i]


def rotate(v):
    v[2], v[0], v[6], v[8] = v[0], v[6], v[8], v[2]
    v[1], v[3], v[7], v[5] = v[3], v[7], v[5], v[1]


memo = dict()


def dp(v):
    res = result(v)
    if res != 0:
        return res
    tmp = v[:]
    key = v[:]
    for i in range(2):
        for j in range(4):
            rotate(tmp)
            key = min(key, tmp)
        reflect(tmp)
    key = tuple(key)
    if key in memo:
        return memo[key]
    ans = -1
    for i in range(9, 11):
        if v[i] == 0:
            continue
        for j in range(9):
            if abs(v[j]) >= i - 8:
                continue
            cp = v[:]
            cp[j] = i - 8
            cp[i] -= 1
            flip(cp)
            sub = dp(cp)
            ans = max(ans, -sub)
    for i in range(9):
        if v[i] <= 0:
            continue
        for j in range(9):
            if v[j] == 0:
                continue
            if abs(v[j]) >= abs(v[i]):
                continue
            cp = v[:]
            cp[j] = cp[i]
            cp[i] = 0
            flip(cp)
            sub = dp(cp)
            ans = max(ans, -sub)
    memo[key] = ans
    return ans


def moves(v):
    res = []
    for i in range(9, 11):
        if v[i] == 0:
            continue
        for j in range(9):
            if abs(v[j]) >= i - 8:
                continue
            cp = v[:]
            cp[j] = i - 8
            cp[i] -= 1
            res.append(cp)
    for i in range(9):
        if v[i] <= 0:
            continue
        for j in range(9):
            if v[j] == 0:
                continue
            if abs(v[j]) >= abs(v[i]):
                continue
            cp = v[:]
            cp[j] = cp[i]
            cp[i] = 0
            res.append(cp)
    return res


def to_board(s):
    res = []
    for c in s:
        res.append("Oo.xX".index(c) - 2)
    return res


def print_state(s):
    outp = "Oo.xX"
    to_prnt = ""
    for i in range(9):
        to_prnt += outp[s[i] + 2]
        if i % 3 == 2:
            print(to_prnt)
            to_prnt = ""


state = [0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 4, 2]
first_move = True
while True:
    if first_move:
        state[0] = 1
        state[9] -= 1
        print_state(state)
        first_move = False
    else:
        for poss in moves(state):
            flip(poss)
            if dp(poss) != -1:
                continue
            flip(poss)
            state = poss
            print_state(state)
            break
    inp = ""
    for i in range(3):
        line = input().strip()
        if line in ["Sigur!", "Tap!"]:
            exit(0)
        inp += line
    board = to_board(inp)
    prv_cnt = [0, 0, 0, 0, 0]
    cur_cnt = [0, 0, 0, 0, 0]
    for i in range(9):
        prv_cnt[state[i] + 2] += 1
        cur_cnt[board[i] + 2] += 1
        state[i] = board[i]
    if prv_cnt[0] < cur_cnt[0]:
        state[12] -= 1
    if prv_cnt[1] < cur_cnt[1]:
        state[11] -= 1
