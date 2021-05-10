import random

n = random.randint(3, 5)

nums = [i + 1 for i in range(n)]

random.shuffle(nums)

print(n)
print(" ".join([str(x) for x in nums]))
