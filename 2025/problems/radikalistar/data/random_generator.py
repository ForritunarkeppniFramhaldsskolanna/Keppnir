#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_n = int(sys.argv[1])
n = random.randint(max(1, 9 * max_n // 10), max_n)

max_q = int(sys.argv[2])
q = random.randint(max(1, 9 * max_q // 10), max_q)

typ = sys.argv[3]

if typ == "pluck-1":
    print(n, q)
    taken = set()
    taken_lst = []
    for i in range(q):
        if random.randint(1, 10) != 1:
            x = random.randint(0, n - 1)
            if x in taken:
                x = random.randint(0, n - 1)
            taken.add(x)
            taken_lst.append(x)
            print("r", 1, x + 1)
        elif random.randint(1, 2) == 1:
            print("s")
        else:
            x = random.choice(taken_lst)
            print("m", x + 1)

if typ == "sqrt":
    bsz = 800
    buckets = []
    for i in range(min(q // 2 - 1, 800)):
        if 800 * i >= n:
            break
        buckets.append([])
        for j in range(800):
            if 800 * i + j >= n:
                break
            buckets[-1].append(800 * i + j)
    done = set()
    todo = []
    for i in range(len(buckets)):
        todo.append(i)
        todo.append(i)
    random.shuffle(todo)
    print(n, len(todo) + 1)
    for x in todo:
        if x in done:
            print("m", random.choice(buckets[x]) + 1)
        else:
            random.shuffle(buckets[x])
            entr = " ".join(str(y + 1) for y in buckets[x])
            print("r", len(buckets[x]), entr)
    print("s")

if typ == "print-orig":
    print(100005, 100000)
    shuf = list(range(1, 100001))
    random.shuffle(shuf)
    for i in range(25000):
        print("r 4", *shuf[4 * i : 4 * i + 4])
    for i in range(75000):
        if random.randint(1, 10) == 1:
            print("s")
        else:
            print("m", random.randint(100001, 100005))
