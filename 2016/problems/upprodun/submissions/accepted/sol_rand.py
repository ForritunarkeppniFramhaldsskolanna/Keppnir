import sys
import random
random.seed(1337)

stofur = int(sys.stdin.readline())
keppendur = int(sys.stdin.readline())

ans = []
for i in range(stofur):
    here = keppendur // stofur
    if i < keppendur % stofur:
        here += 1
    ans.append('*' * here)

random.shuffle(ans)
for l in ans:
    print(l)

