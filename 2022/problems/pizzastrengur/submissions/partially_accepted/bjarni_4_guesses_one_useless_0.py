#!/usr/bin/python3

n = int(input())
res = -1
cs = ['P', 'I', 'Z', 'A']
ans = ""
print("P")
res = int(input())
res = -1
while res != 2:
    for c in cs:
        print(ans + c, flush=True)
        res = int(input())
        if res != 0:
            ans += c
            break
