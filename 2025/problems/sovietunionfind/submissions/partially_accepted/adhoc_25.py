n, q = map(int, input().strip().split())
# independent, 1 rules, 2 rules
state = 0
for _ in range(q):
    inp = input().strip().split()
    if inp[0] == "a":
        if inp[1] == inp[2]:
            continue
        if inp[1] == "1":
            state = 1
        if inp[1] == "2":
            state = 2
    elif inp[0] == "b":
        state = 0
    elif inp[0] == "c":
        if state != 0:
            print(state)
        else:
            print(inp[1])
    else:
        assert False
