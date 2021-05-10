import random

n = random.randint(500, 1000)

nums = [i + 1 for i in range(n)]

random.shuffle(nums)

print(n)
print(" ".join([str(x) for x in nums]))
