n, q = map(int, input().strip().split())
rules = [[i] for i in range(n)]
ruled_by = [i for i in range(n)]
for _ in range(q):
    inp = input().strip().split()
    if inp[0] == "a":
        x, y = map(int, inp[1:])
        x, y = x - 1, y - 1
        x, y = ruled_by[x], ruled_by[y]
        if x == y:
            continue
        for z in rules[y]:
            rules[x].append(z)
            ruled_by[z] = x
        rules[y] = []
    elif inp[0] == "b":
        x = int(inp[1]) - 1
        x = ruled_by[x]
        todo = rules[x][:]
        for z in todo:
            ruled_by[z] = z
            rules[z] = [z]
    elif inp[0] == "c":
        x = int(inp[1]) - 1
        print(ruled_by[x] + 1)
    else:
        assert False
