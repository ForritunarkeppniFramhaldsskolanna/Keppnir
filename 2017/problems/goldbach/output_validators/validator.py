import sys

def is_witness(n, a):
    if a > n-2:
        return False
    d = n-1
    r = 0
    while d % 2 == 0:
        r += 1
        d /= 2
    x = pow(a, d, n)
    if x == 1 or x == n-1:
        return False
    for i in range(r-1):
        x = x * x % n
        if x == 1:
            return True
        if x == n-1:
            return False
    return True

def is_probable_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    a = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 61, 73, 1662803]
    for x in a:
        if is_witness(n, x):
            return False
    return True


with open(sys.argv[1], 'r') as f:
    n = int(f.read().strip())

nums = []
started = False
cur = 0
for c in sys.stdin.read():
    if ord('0') <= ord(c) <= ord('9'):
        started = True
        cur = cur * 10 + ord(c) - ord('0')
    elif started:
        nums.append(cur)
        started = False
        cur = 0

if started:
    nums.append(cur)

def WA():
    sys.exit(43)

if len(nums) != 3:
    WA()

for x in nums:
    if x < 2 or x > n:
        WA()

if sum(nums) != n:
    WA()

for x in nums:
    if not is_probable_prime(x):
        WA()

sys.exit(42)

