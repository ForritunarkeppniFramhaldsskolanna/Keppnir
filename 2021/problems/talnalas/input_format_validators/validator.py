import sys
import re
import string

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = map(int, line.split())
assert 1 <= n <= 50
assert 1 <= m <= 10**5

nums = set()
for i in range(m+2):
    line = sys.stdin.readline()
    assert re.match('^[0-9]+\n$', line)
    line = line.strip()
    assert all( c in string.digits for c in line )
    assert line not in nums
    nums.add(line)

assert not sys.stdin.read()
sys.exit(42)
