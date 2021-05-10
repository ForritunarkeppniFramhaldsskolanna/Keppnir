import random

n = random.randint(1, 1000)
q = random.randint(1, 10 ** 4)
print(n, q)

for i in range(q):
    c = random.randint(1, 3)
    if c == 1:
        print(1, random.randint(1, n))
    elif c == 2:
        print(2, random.randint(1, n), random.randint(1, n), random.randint(1, 10 ** 9))
    else:
        print(3, random.randint(1, n), random.randint(1, n))
