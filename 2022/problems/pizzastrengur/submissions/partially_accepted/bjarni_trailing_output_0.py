#!/usr/bin/python3
import random

random.seed(1337)
n = int(input())
res = -1
cs = ['P', 'I', 'Z', 'A']
ans = ""
while res != 2 and len(ans) != n:
    random.shuffle(cs)
    for i in range(len(cs)):
        if i == len(cs) - 1:
            ans += cs[i]
            break
        print(ans + cs[i], flush=True)
        res = int(input())
        if res != 0:
            ans += cs[i]
            break
if res != 2:
    print(ans, flush=True)
print("PIZZAPARTY!!!")
