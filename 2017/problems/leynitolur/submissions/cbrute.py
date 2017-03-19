import sys

a = 230309227
b = 68431307
for line in sys.stdin.read().strip().split():
    x = int(line)
    t = 0
    ok = False
    for i in range(1000): # Higher number takes longer, but gives more points
        if (x - b + t * (2**64)) % a == 0:
            print((x - b + t * (2**64)) // a)
            ok = True
            break
        t += 1
    if not ok:
        print('0')

