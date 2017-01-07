import sys
import re

a = sys.stdin.readline()
b = sys.stdin.readline()

assert re.match('^[0-9]+(\\.[0-9]+)?\n$', a)
assert re.match('^[0-9]+(\\.[0-9]+)?\n$', b)

a = float(a.strip())
b = float(b.strip())

assert 0 < a <= 10**4
assert 0 < b <= 10**4
assert a >= b

assert sys.stdin.read() == ''
sys.exit(42)
