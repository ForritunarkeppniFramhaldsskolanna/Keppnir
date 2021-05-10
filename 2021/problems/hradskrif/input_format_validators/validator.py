import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
m = int(line)
assert 1 <= m <= 5*10**5

line = sys.stdin.readline()
assert re.match('^[A-Z ]+\n$', line)
assert 1 <= len(line)-1 <= 10**6 # subtract one for newline

assert not sys.stdin.read()
sys.exit(42)
