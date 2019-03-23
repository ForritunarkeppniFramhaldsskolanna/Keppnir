import sys
import re

line = sys.stdin.readline()
assert(re.match('^[1-9][0-9]*\n$', line))
n = int(line)

assert(1 <= n <= 10**5)

line = sys.stdin.readline()
assert(re.match('^[0-1]*\n$', line))
assert(len(line.rstrip('\n')) == n)
line = sys.stdin.readline()
assert(re.match('^[0-1]*\n$', line))
assert(len(line.rstrip('\n')) == n)

assert(not sys.stdin.read())
sys.exit(42)
