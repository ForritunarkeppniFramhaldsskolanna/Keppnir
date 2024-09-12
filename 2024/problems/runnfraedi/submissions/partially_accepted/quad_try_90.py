#!/usr/bin/env python3
import sys

try:
    sys.set_int_max_str_digits(0)
except Exception: # in case kattis does not have 3.10
    pass

s1 = input().strip()
s2 = input().strip()
if s1 == s2 or s2 == "0.0":
    print("Veit ekki")
    exit(0)
if len(s1.split('.')[0]) < len(s2.split('.')[0]):
    print("Runnun")
    exit(0)
trc = False
rnd = False
a = [c for c in s1 if c != '.']
b = [c for c in s2 if c != '.']
n = len(a)
for i in range(len(b)):
    acp = a[:]
    for j in range(i + 1, n):
        acp[j] = '0'
    if acp[:len(b)] == b:
        trc = True
        if a[i + 1] < '5':
            rnd = True
    if a[i + 1] < '5':
        continue
    aprf = list(str(int("".join(a[:i+1])) + 1))
    asuf = ["0" for _ in range(len(a[i+1:]))]
    acp = aprf + asuf
    if acp[:len(b)] == b:
        rnd = True
    
if trc and rnd:
    print("Veit ekki")
elif trc:
    print("Styfun")
else:
    print("Runnun")
