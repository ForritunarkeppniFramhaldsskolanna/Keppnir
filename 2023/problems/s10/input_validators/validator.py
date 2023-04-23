#!/usr/bin/python3
import sys
import re

def assert_plate(line):
    assert re.match('[0-9A-Z]{2,6}\n', line)

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, k = map(int, line.split())
assert 1 <= n <= 10**5
assert 1 <= k <= 10**5

plates = set()
n_sum = 0
m_sum = 0
for i in range(k):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]* [1-9][0-9]*\n', line), repr(line)
    n_i, m_i = map(int, line.split())
    n_sum += n_i
    m_sum += m_i
    for j in range(m_i):
        line = sys.stdin.readline()
        assert_plate(line)
        assert line not in plates
        plates.add(line)

assert n_sum <= n

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
m = int(line)

#assert m_sum <= 2*n
assert m_sum + m <= 4*10**5

for i in range(m):
    line = sys.stdin.readline()
    assert_plate(line)

assert not sys.stdin.read()
sys.exit(42)
