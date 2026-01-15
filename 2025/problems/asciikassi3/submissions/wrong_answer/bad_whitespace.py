#!/usr/bin/python3
h, w, d = map(int, input().strip().split())
outp = [[0 for _ in range(w + d)] for _ in range(h + d)]
for off in [(0, d - 1), (d - 1, 0)]:
    for i in range(w):
        outp[off[0]][i + off[1]] |= 1
        outp[off[0] + h - 1][i + off[1]] = 1
    for i in range(h):
        outp[i + off[0]][off[1]] |= 2
        outp[i + off[0]][off[1] + w - 1] |= 2
for y_off in [0, h - 1]:
    for x_off in [0, w - 1]:
        st = (d - 1 + y_off, x_off)
        nd = (y_off, d - 1 + x_off)
        outp[st[0]][st[1]] |= 8
        outp[nd[0]][nd[1]] |= 8
        for k in range(1, d):
            pos = (st[0] - k, st[1] + k)
            outp[pos[0]][pos[1]] |= 4

for i in range(len(outp)):
    for j in range(len(outp[i])):
        if outp[i][j] & 8:
            outp[i][j] = "+"
        elif outp[i][j].bit_count() > 1:
            outp[i][j] = "x"
        elif outp[i][j] == 4:
            outp[i][j] = "/"
        elif outp[i][j] == 2:
            outp[i][j] = "|"
        elif outp[i][j] == 1:
            outp[i][j] = "-"
        else:
            outp[i][j] = " "

for l in outp:
    print("".join(l))
