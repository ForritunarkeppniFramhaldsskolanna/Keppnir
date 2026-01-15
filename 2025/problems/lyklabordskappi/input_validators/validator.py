import re
import sys

min_n, max_n = 1, 10**3
min_l, max_l = 4, 10
min_t, max_t = 1, 5
min_w, max_w = 1, 20

exec(sys.argv[1])  # min_n
exec(sys.argv[2])  # max_n
exec(sys.argv[3])  # min_l
exec(sys.argv[4])  # max_l
exec(sys.argv[5])  # min_t
exec(sys.argv[6])  # max_t
exec(sys.argv[7])  # min_w
exec(sys.argv[8])  # max_w

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$", line)
n, l, t = map(int, line.strip().split())
assert min_n <= n <= max_n
assert min_l <= l <= max_l
assert min_t <= t <= max_t

line = sys.stdin.readline()
assert re.match("^(\S* )*\S*\n$", line)

words = line.strip().split()

assert len(words) == n

for word in words:
    assert min_w <= len(word) <= max_w

assert not sys.stdin.read()
sys.exit(42)
