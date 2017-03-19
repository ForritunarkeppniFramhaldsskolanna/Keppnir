import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line.strip())

assert 5 < n <= 10**8
assert n % 2 != 0

assert sys.stdin.read() == ''
sys.exit(42)

