#!/usr/bin/python3
import sys

if __name__ == "__main__":
    n, q = sys.stdin.readline().split()
    n, q = int(n), int(q)

    index = [[0 if i == j else -1 for i in range(n)] for j in range(n)]
    desc = [[[]] for _ in range(n)]

    for _ in range(q):
        o, x, y = sys.stdin.readline().split()
        o, x, y = int(o), int(x) - 1, int(y) - 1
        if o == 1:
            if index[x][y] != -1:
                sys.stdout.write("Jebb\n")
            else:
                sys.stdout.write("Neibb\n")
        elif index[x][y] == -1:
            for i in range(n):
                if index[i][x] != -1 and index[i][y] == -1:
                    to_meld = [(i, y, x, y)]
                    while len(to_meld) > 0:
                        r, s, u, v = to_meld.pop()
                        index[r][v] = len(desc[r])
                        desc[r].append([])
                        desc[r][index[r][u]].append(v)
                        if index[s][v] != -1:
                            for z in desc[s][index[s][v]]:
                                if index[r][z] == -1:
                                    to_meld.append((r, s, v, z))
