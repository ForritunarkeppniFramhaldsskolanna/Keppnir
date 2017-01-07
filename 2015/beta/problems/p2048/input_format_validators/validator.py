import sys
import re

items = {2**i for i in range(1, 11)}
items.add(0)

for i in range(4):
    l = sys.stdin.readline()
    assert re.match('^[0-9]+ [0-9]+ [0-9]+ [0-9]+\n$', l)
    l = l.strip()
    for p in l.split():
        p = int(p)
        assert p in items

assert sys.stdin.readline() in {'DOWN\n', 'LEFT\n', 'RIGHT\n', 'UP\n'}

assert sys.stdin.read() == ''
sys.exit(42)
