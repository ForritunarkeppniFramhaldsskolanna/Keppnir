#!/usr/bin/env python3
import sys

st_left = 26
nonz = [26 for _ in range(26)]
avail = [(1 << 26) - 1 for _ in range(26 * 26)]

n = int(sys.stdin.readline())

for _ in range(n):
    if st_left == 0:
        sys.stdout.write(":(\n")
        continue
    airport = sys.stdin.readline().strip().upper()
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
        if nonz[ord(airport[i]) - ord('A')] == 0:
            continue
        for j in range(i + 1, len(airport) - 1):
            if done:
                break
            key = 26 * (ord(airport[i]) - ord('A')) + ord(airport[j]) - ord('A')
            if (avail[key] & msk[j + 1]) == 0:
                continue
            for k in range(j + 1, len(airport)):
                ind = ord(airport[k]) - ord('A')
                if (avail[key] & (1 << ind)) == 0:
                    continue
                avail[key] ^= 1 << ind
                if avail[key] == 0:
                    nonz[ord(airport[i]) - ord('A')] -= 1
                    if nonz[ord(airport[i]) - ord('A')] == 0:
                        st_left -= 1
                sys.stdout.write("".join([airport[i], airport[j], airport[k]]))
                sys.stdout.write("\n")
                done = True
                break
    if not done:
        sys.stdout.write(":(\n")

