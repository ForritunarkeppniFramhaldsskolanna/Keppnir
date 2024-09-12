#!/usr/bin/python3
import string

def solve_cur(avail, airport, commit):
    msk = [0 for i in range(len(airport))]
    for i in reversed(range(len(airport))):
        msk[i] |= 1 << (ord(airport[i]) - ord('A'))
        if i + 1 != len(airport):
            msk[i] |= msk[i + 1]
    tried = set()
    for i in range(len(airport)):
        if airport[i] in tried:
            continue
        tried.add(airport[i])
        for j in range(i + 1, len(airport) - 1):
            key = (airport[i], airport[j])
            if (avail[key] & msk[j + 1]) == 0:
                continue
            for k in range(j + 1, len(airport)):
                ind = ord(airport[k]) - ord('A')
                if (avail[key] & (1 << ind)) == 0:
                    continue
                if commit:
                    avail[key] ^= 1 << ind
                return "".join([airport[i], airport[j], airport[k]])
    return ":("

import sys
import random

random.seed(int(sys.argv[-1]))

max_n = int(sys.argv[1])
max_m = int(sys.argv[2])
max_c = int(sys.argv[3])

k = [2, 4, 8, 14, 26][int(sys.argv[4]) % 5]
allowed_letters = string.ascii_uppercase[:k] + string.ascii_lowercase[:k]

def random_name():
    l = random.choice([max_m, random.randint(max_m // 2, max_m)])
    return "".join([random.choice(allowed_letters) for _ in range(l)])

n = random.choice([max_n, random.randint(max_n // 2, max_n)])
n = max(1, n)

print(n)

avail = dict()

for c1 in range(ord('A'), ord('Z') + 1):
    for c2 in range(ord('A'), ord('Z') + 1):
        avail[(chr(c1), chr(c2))] = (1 << 26) - 1

for _ in range(n):
    nam = ""
    while True:
        nam = random_name()
        sol = solve_cur(avail, nam.upper(), False)
        if sol == ":(" or max_c == 3:
            break
        if max_c != 3 and sol[:3 - max_c] == nam[:3 - max_c].upper():
            break
    solve_cur(avail, nam.upper(), True)
    print(nam)
