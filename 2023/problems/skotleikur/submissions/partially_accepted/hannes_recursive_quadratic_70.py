#!/usr/bin/env python3

import sys, math

sys.setrecursionlimit(20000)

K = int(input())
a = int(input())
b = int(input())

computed = set()

sols = set()

def solve(total, kills, assists):
    #print(f"total: {total}, kills: {kills}, assists: {assists}")
    # if we already computed this, bail out
    if (total, kills, assists) in computed:
        #print(f"bailing out, as we have seen ({total}, {kills}, {assists})")
        return
    # found a sol
    if total == 0:
        #print("total is 0")
        sols.add((kills, assists))
        # mark this computation as done
        computed.add((total, kills, assists))
        return
    # we cant get a sol
    #print(f"total: {total}, k: {kills*a}, a: {assists*b}")
    if total < 0:
        # mark this computation as done
        computed.add((total, kills, assists))
        return

    # mark this computation as done
    computed.add((total, kills, assists))

    solve(total - a, kills + 1, assists)
    solve(total - b, kills, assists + 1)

solve(K, 0, 0)
if K == 0:
    sols.clear()
    sols.add((0, 0))

print(len(sols))
for kill, assist in sols:
    print(kill, assist)
    # print(kill*a, assist*b)
    # print(((kill*a) + (assist*b)))
    # print()