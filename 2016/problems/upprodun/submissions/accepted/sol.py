import sys
stofur = int(sys.stdin.readline())
keppendur = int(sys.stdin.readline())

for i in range(stofur):
    here = keppendur // stofur
    if i < keppendur % stofur:
        here += 1
    print('*' * here)

