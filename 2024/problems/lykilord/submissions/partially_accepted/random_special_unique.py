#!/usr/bin/python3
import random
import string

charset = [chr(i) for i in range(33,127) if chr(i) not in (string.ascii_letters + string.digits)]

def random_string():
    n = random.randint(0, 32)
    return ''.join(random.choices(charset, k=n))

_, m = map(int, input().split())
seen = set()

print("Mogulegt!")
for i in range(m):
    s = random_string()
    while s in seen:
        s = random_string()
    seen.add(s)
    print(s)
