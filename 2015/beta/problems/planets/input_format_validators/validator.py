import sys
import re

n = sys.stdin.readline()
assert re.match('\d+\n$', n)

earth = sys.stdin.readline()
assert re.match('-?\d+(\.\d+)? -?\d+(\.\d+)? -?\d+(\.\d+)?\n', earth)

for c in earth.split():
    assert -10000 <= float(c) <= 10000

for i in range(int(n)):
    planet = sys.stdin.readline()
    assert re.match('-?\d+(\.\d+)? -?\d+(\.\d+)? -?\d+(\.\d+)?\n', planet)

    for c in planet.split():
        assert -10000 <= float(c) <= 10000

assert sys.stdin.read() == ''
sys.exit(42)
