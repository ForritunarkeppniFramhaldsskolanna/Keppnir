import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 10**5

for i in range(n):
    row = sys.stdin.readline().strip()
    assert len(row.split(" ")) == 2
    name, price = row.split(" ")
    price = int(price)
    assert (price > 0) and price < (10**9)

assert not sys.stdin.read()
sys.exit(42)
