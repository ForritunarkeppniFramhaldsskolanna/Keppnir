import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 100000

items = set()
for i in range(n):
    s = sys.stdin.readline()
    assert re.match('^[a-z_]{1,20}\n$', s)
    s = s.strip()
    assert s not in items
    assert s != 'impossible'
    items.add(s)

m = sys.stdin.readline()
assert re.match('^[0-9]+\n$', m)
m = int(m.strip())
assert 0 <= m <= 100000

bad = set()
for i in range(m):
    s = sys.stdin.readline()
    assert re.match('^[a-z_]{1,20} [a-z_]{1,20}\n$', s)
    s = s.strip()
    p, q = s.split(' ', 1)
    assert p in items
    assert q in items
    assert (p, q) not in bad
    assert (q, p) not in bad
    bad.add((p, q))

assert sys.stdin.read() == ''

sys.exit(42)
