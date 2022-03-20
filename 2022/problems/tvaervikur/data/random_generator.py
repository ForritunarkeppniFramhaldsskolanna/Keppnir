#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
n = random.randint(1, max_n)
B = int(2 ** random.uniform(0, 20))

print(n, B)

if random.randint(1, 2) == 1:
    nums = [random.randint(1, 10 ** 9) for i in range(n)]
    print(" ".join([str(x) for x in nums]))
else:
    nums = [random.randint(1, 10 ** 3) for i in range(n - 1)]
    s = sum([x // B for x in nums])
    nums.append(random.randint(s * B + 1, 10 ** 9))
    random.shuffle(nums)
    print(" ".join([str(x) for x in nums]))
