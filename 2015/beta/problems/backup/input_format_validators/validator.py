import sys
import re

line = sys.stdin.readline()
assert re.match('^[0-9]+ [0-9]+\n$', line)
n, m = map(int, line.strip().split())
assert 1 <= n <= 1000
assert 1 <= m <= 1000

def parse(size):
    suffixes = [
        ('GB', 1024**3),
        ('MB', 1024**2),
        ('KB', 1024**1),
        ('B', 1024**0),
    ]
    for suffix, mult in suffixes:
        if size.endswith(suffix):
            part = int(size[:-len(suffix)])
            assert 1 <= part < 1024
            return mult * part
    assert False


file_names = set()
need = 0
for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[0-9a-zA-Z/_.]+ [0-9]+[KMG]?B$\n', line)
    name, size = line.split()
    assert name not in file_names
    file_names.add(name)
    size = parse(size)
    assert 1 <= size <= 1023 * 1024**3
    need += size

disk_name = set()
mn = 1000000000000000000000000000000000000000
mn_cnt = 0
for i in range(m):
    line = sys.stdin.readline()
    assert re.match('^[0-9a-zA-Z/_.]+ [0-9]+[KMG]?B [0-9]+\n$', line)
    name, size, cost = line.split()
    assert name not in disk_name
    disk_name.add(name)
    size = parse(size)
    assert 1 <= size <= 1023 * 1024**3
    cost = int(cost)
    assert 1 <= cost < 2**30
    if size >= need:
        if cost < mn:
            mn = cost
            mn_cnt = 0
        if cost == mn:
            mn_cnt += 1

assert mn_cnt == 1

assert sys.stdin.read() == ''

sys.exit(42)
