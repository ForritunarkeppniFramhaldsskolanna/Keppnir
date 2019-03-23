import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$', line)
n, r, c = map(int, line.split())

assert 4 <= n <= 10**5
assert 2 <= c
assert n == r * c

names = []
for i in range(r):
    line = sys.stdin.readline()
    print(line)
    assert re.match('^([a-z]+ )+[a-z]+\n$', line)
    assert len(line.split()) == c
    names.extend(line.split())


# assert that no two names are alike

name_count = {}

for i in range(len(names)):
    if names[i] not in name_count:
        name_count[names[i]] = 1
    else:
        name_count[names[i]] += 1
    assert name_count[names[i]] == 1

names = set(names)
for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[a-z]+\n$', line)
    assert line.strip() in names


assert not sys.stdin.read()
exit(42)
