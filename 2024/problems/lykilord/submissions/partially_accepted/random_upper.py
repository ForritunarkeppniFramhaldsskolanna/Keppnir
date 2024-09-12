#!/usr/bin/python3
import random
import string

charset = string.ascii_uppercase

def random_string():
    n = random.randint(0, 32)
    return ''.join(random.choices(charset, k=n))

_, m = map(int, input().split())

print("Mogulegt!")
for i in range(m):
    print(random_string())
