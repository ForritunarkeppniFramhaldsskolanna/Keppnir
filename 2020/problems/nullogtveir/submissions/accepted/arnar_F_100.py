#!/usr/bin/python3
n = input()
k = len(n)

def cnt(at, eq):
    if at == k:
        return 1
    if not eq:
        return 2**(k-at)
    if n[at] == '0':
        return cnt(at+1, True)
    elif n[at] == '1':
        return cnt(at+1, False)
    elif n[at] == '2':
        return cnt(at+1, False) + cnt(at+1, True)
    else:
        return 2*cnt(at+1, False)

print(cnt(0, True))
