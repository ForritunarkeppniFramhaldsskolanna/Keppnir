import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 3000

nums = []
for i in range(n + 2):
    m = sys.stdin.readline()
    assert re.match('^-?[0-9]+\\.[0-9]{2}$\n', m)
    m = float(m.strip())
    assert -2000-1e-9 <= m <= 2000+1e-9
    nums.append(m)

a0 = nums[0]
anp1 = nums[1]
c = nums[2:]

lo = -10000
hi = 10000
for it in range(1000):
    a1 = (lo + hi) / 2.0
    a = [a0,a1]
    while len(a) < n + 2:
        i = len(a)-1
        a.append(2*a[i] - a[i-1] + 2*c[i-1])

    if a[n+1] < anp1:
        lo = a1
    else:
        hi = a1

# a_{i+1} = 2*a_i - a_{i-1} + 2*c_i

assert -2000-1e-9 <= lo <= 2000+1e-9
assert -2000-1e-9 <= hi <= 2000+1e-9

for i in range(len(a)):
    assert -2000-1e-9 <= a[i] <= 2000+1e-9

assert sys.stdin.read() == ''

sys.exit(42)
