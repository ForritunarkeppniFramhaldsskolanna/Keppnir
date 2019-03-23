import sys
import re
import string

line = sys.stdin.readline().rstrip('\n')
for x in line:
    assert(x in ' '+string.ascii_letters+string.digits+string.punctuation)
assert(1 <= len(line) <= 1000)
assert(not sys.stdin.read())
sys.exit(42)
