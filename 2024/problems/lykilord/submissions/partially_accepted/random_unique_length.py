#!/usr/bin/python3
import random

charset = [chr(i) for i in range(33,127)]

min_length = 0
max_length = 32

def random_string():
    n = random.randint(min_length, max_length)
    return ''.join(random.choices(charset, k=n))

n, m = map(int, input().split())
seen = set()

for _ in range(n):
    k = int(input())
    for _ in range(k):
        line = input()
        if line.endswith(" symbols"):
            if line.startswith("contain at most "):
                max_length = min((max_length, int(line[16:-8])))
            elif line.startswith("contain at least "):
                min_length = max((min_length, int(line[17:-8])))

print("Mogulegt!")
for i in range(m):
    s = random_string()
    while s in seen:
        s = random_string()
    seen.add(s)
    print(s)
