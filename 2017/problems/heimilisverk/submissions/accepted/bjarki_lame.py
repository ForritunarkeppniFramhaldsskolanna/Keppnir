import sys

n = int(sys.stdin.readline())
seen = set()
for _ in range(n):
    s = sys.stdin.readline()
    assert s[-1] == '\n'
    s = s[:-1]
    if s not in seen:
        print(s)
    seen.add(s)

