#!/usr/bin/python3
import sys, random, math

def exp_rand(n):
    mx = 10 ** 18 if random.randint(1, 25) == 1 else n
    lg = random.uniform(0, math.log(n))
    ex = math.exp(lg)
    ex = int(ex)
    ex = max(ex, 0)
    ex = min(ex, mx)
    return ex

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
max_m = eval(sys.argv[2])
fixed_size = eval(sys.argv[3])

n = random.choice([max_n, random.randint(max_n // 2, max_n)])
m = random.choice([max_m, random.randint(max_m // 2, max_m)])
print(n, m)
ka = exp_rand(n)
kb = exp_rand(n)
print(ka, kb)
if m != 0:
    print(*[exp_rand(n) for _ in range(m)])
