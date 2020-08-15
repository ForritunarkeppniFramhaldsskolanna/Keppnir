import sys
import re

#line = sys.stdin.readline()

line1 = sys.stdin.readline()
line2 = sys.stdin.readline()
assert re.match('^[a-z]+\n$', line1)
assert re.match('^[a-z]+\n$', line2)
assert line1[-1] == '\n'
assert line2[-1] == '\n'
assert len(line1.strip()) == len(line2.strip())

assert not sys.stdin.read()
sys.exit(42)
