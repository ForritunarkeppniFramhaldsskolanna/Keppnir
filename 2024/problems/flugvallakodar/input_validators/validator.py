#!/usr/bin/env python3

def solve(airports):
    res = []
    avail = dict()

    for c1 in range(ord('A'), ord('Z') + 1):
        for c2 in range(ord('A'), ord('Z') + 1):
            avail[(chr(c1), chr(c2))] = (1 << 26) - 1

    n = len(airports)

    for airport in airports:
        msk = [0 for i in range(len(airport))]
        for i in reversed(range(len(airport))):
            msk[i] |= 1 << (ord(airport[i]) - ord('A'))
            if i + 1 != len(airport):
                msk[i] |= msk[i + 1]
        tried = set()
        done = False
        for i in range(len(airport)):
            if done:
                break
            if airport[i] in tried:
                continue
            tried.add(airport[i])
            for j in range(i + 1, len(airport) - 1):
                if done:
                    break
                key = (airport[i], airport[j])
                if (avail[key] & msk[j + 1]) == 0:
                    continue
                for k in range(j + 1, len(airport)):
                    ind = ord(airport[k]) - ord('A')
                    if (avail[key] & (1 << ind)) == 0:
                        continue
                    avail[key] ^= 1 << ind
                    res.append("".join([airport[i], airport[j], airport[k]]))
                    done = True
                    break
        if not done:
            res.append(":(")

    return res


import re
import sys

exec(sys.argv[1]) # max_n
exec(sys.argv[2]) # max_m
exec(sys.argv[3]) # max_change

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert 1 <= n <= max_n

airports = []
total_len = 0

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[a-zA-Z]+\n$", line)
    airport = line.strip()
    assert 3 <= len(airport) <= max_m
    airports.append(airport.upper())
    total_len += len(airport)

assert total_len <= 2 * 10 ** 6

if max_change < 3:
    out = solve(airports)
    for i in range(n):
        if out[i] == ":(":
            continue
        if max_change <= 2:
            assert out[i][0] == airports[i][0]
        if max_change <= 1:
            assert out[i][1] == airports[i][1]
        if max_change <= 0:
            assert out[i][2] == airports[i][2]

assert not sys.stdin.read()
exit(42)

