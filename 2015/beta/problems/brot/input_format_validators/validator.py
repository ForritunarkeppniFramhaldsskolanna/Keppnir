import sys
import re

n = sys.stdin.readline()

assert re.match('\d+(\.\d+)?\n$', n)

if re.search("\.", n) is not None:
    after = str.split(n.rstrip(), ".")[1]
    assert(len(after) < 10)

assert sys.stdin.read() == ''

sys.exit(42)
