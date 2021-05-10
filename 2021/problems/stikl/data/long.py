import sys
import random

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
q = int(sys.argv[2])
s = int(sys.argv[3])

nums = set()
while len(nums) < n:
    nums.add(random.randint(1, 10**9))
nums = list(sorted(nums))

print('%d %d' % (n,q))
print(' '.join(map(str, nums[:-1][::-1] + nums[-1:])))

for i in range(q):
    print('%d %d' % (random.randint(1, n), random.randint(1, s)))

