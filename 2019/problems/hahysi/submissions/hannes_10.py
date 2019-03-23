#!/usr/bin/env python3
n, m = [int(i) for i in input().split()]

cntr = 0

for upleft_x in range(0, n):
    for upleft_y in range(0, m):
        for upright_x in range(0, n):
            for upright_y in range(0, m):
                for downright_x in range(0, n):
                    for downright_y in range(0, m):
                        for downleft_x in range(0, n):
                            for downleft_y in range(0, m):
                                if upleft_x == downleft_x and upleft_y == upright_y and upright_x == downright_x and downleft_y == downright_y:
                                    if (abs(upleft_x - upright_x) * abs(upleft_y - downleft_y)) > 0:
                                        cntr += 1

mod = (10**9) + 7
print(cntr//4 % mod)