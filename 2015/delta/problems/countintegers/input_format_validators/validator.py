import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 10**10

line = sys.stdin.readline()
assert re.match('^[0-9]+ [0-9]+\n$', line)
i,j = map(int, line.strip().split())
assert 1 <= i <= n
assert 1 <= j <= n

assert sys.stdin.read() == ''
sys.exit(42)
