#!/usr/bin/python3

n = int(input())
print("P" * (10**4 + 1))
res = -1
cs = ['P', 'I', 'Z', 'A']
ans = ""
while res != 2:
    for c in cs:
        print(ans + c, flush=True)
        res = int(input())
        if res != 0:
            ans += c
            break
