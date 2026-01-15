import sys
from string import ascii_letters

lines = 0

ascii_letters += '0123456789"()'

line1 = str(sys.stdin.readline()).strip("\n")
assert 1 <= len(line1) <= 100
for c in line1:
    assert c in ascii_letters

line2 = str(sys.stdin.readline()).strip("\n")
assert 1 <= len(line2) <= 100
for d in line2:
    assert d in ascii_letters

assert not sys.stdin.read()
sys.exit(42)
