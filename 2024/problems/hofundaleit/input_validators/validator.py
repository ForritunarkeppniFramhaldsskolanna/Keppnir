#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # min_n
exec(sys.argv[2]) # max_n
exec(sys.argv[3]) # max_q
exec(sys.argv[4]) # exists (-1 for never, 0 for maybe, 1 for always)
exec(sys.argv[5]) # unique
exec(sys.argv[6]) # order

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$", line)
n, q = map(int, line.strip().split())
assert min_n <= n <= max_n
assert 0 <= q <= max_q

authors = dict()
books = set()
order_check = []
total_len = 0

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[A-Za-z_]+, [A-Za-z_]+\n$", line)
    title, author = line.strip().split(', ')
    if author not in authors:
        authors[author] = set()
    assert title not in books
    books.add(title)
    authors[author].add(title)
    if unique:
        assert len(authors[author]) == 1
    assert 1 <= len(author) <= 25
    assert 1 <= len(title) <= 25
    total_len += len(author)
    total_len += len(title)
    order_check.append((author, title))

if order:
    assert all(order_check[i] <= order_check[i + 1] for i in range(len(order_check) - 1))

for _ in range(q):
    line = sys.stdin.readline()
    assert re.match("^[A-Za-z_]+\n$", line)
    title = line.strip()
    if exists == 1:
        assert title in books
    if exists == -1:
        assert title not in books
    assert 1 <= len(title) <= 25
    total_len += len(title)

assert 0 <= total_len <= 10 ** 6

assert not sys.stdin.read()
sys.exit(42)
