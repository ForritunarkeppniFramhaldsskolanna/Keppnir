import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n ,k= map(int,line.split())
assert 1 <= n <= 2*10**5
assert 1 <= k <= 2*10**5

line = sys.stdin.readline() 
assert re.match('^[.o]+$', line)
assert len(line.strip()) == n
line = sys.stdin.readline() 
assert re.match('^[.o]+$', line)
assert len(line.strip()) == n

for i in range(k):
    line = sys.stdin.readline()
    if line == "Q\n":
        continue
    assert re.match('^U [1-2] [1-9][0-9]*\n$', line)
    x = int(line.split()[1])
    y = int(line.split()[2])
    assert 1 <= x <= 2
    assert 1 <= y <= n

assert not sys.stdin.read()
sys.exit(42)
