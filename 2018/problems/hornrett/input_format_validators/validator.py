import sys
def readline():
    line = sys.stdin.readline().strip('\n')
    assert(line == line.strip())
    return line

def toint(s):
    i = int(s)
    assert(str(i) == s)
    return i

def inrange(lo, n, hi):
    assert(lo <= n <= hi)

def notrash():
    assert(sys.stdin.read() == '')

line = readline().split()
assert(len(line) == 3)
nums = list(map(toint, line))
assert(nums == list(sorted(nums)))
for x in nums:
    inrange(1, x, 10**9)

notrash()
sys.exit(42)
