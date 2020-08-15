import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 1000

used = set()
for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[A-Za-z]{1,100} (0|[1-9][0-9]*)\n$', line)
    name, num = line.split()
    num = int(num)
    assert 0 <= num <= 1000
    assert num not in used
    used.add(num)

assert not sys.stdin.read()
sys.exit(42)
