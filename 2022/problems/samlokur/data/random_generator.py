#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

manual = {
    "break1" : "8 3\n4 7 10 4 4 4 4 9\n3 4 4 3 1 3 4 3",
    "break2" : "5 2\n4 8 8 4 4\n1 1 2 1 2",
}

typ = sys.argv[2]

if typ != "rand":
    print(manual[typ])
    exit(0)

mx = eval(sys.argv[1])
n = random.randint(mx // 2, mx)
k = random.randint(mx // 4, mx // 2 + 1)
print(n, k)

def rand_sand():
    t = random.randint(1, 11)
    if t == 1:
        return random.randint(0, 3)
    if t % 2 == 0:
        return random.randint(5, 10)
    return 4

qual = [rand_sand() for i in range(n)]
times = [random.randint(1, k + 1) for i in range(n)]

print(" ".join([str(x) for x in qual]))
print(" ".join([str(x) for x in times]))
