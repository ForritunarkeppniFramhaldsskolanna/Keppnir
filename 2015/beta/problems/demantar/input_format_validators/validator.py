import sys
import re
import string

s = sys.stdin.readline()
assert re.match('^[0-9]+ .\n$', s)
s = s[:-1]
n, c = s.split(' ', 1)
n = int(n)
assert 1 <= n <= 500
assert len(c) == 1
assert c in string.printable and c not in string.whitespace

assert sys.stdin.read() == ''

sys.exit(42)
