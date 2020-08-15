#!/usr/env/bin python3
n, k = [int(x) for x in input().strip().split()]
mp = [list(input().strip()) for _ in range(2)]
cnt = 0
for i in range(n):
    if mp[0][i] == 'o' and mp[1][i] == 'o':
        cnt += 1
    if i != n - 1 and mp[0][i] == 'o' and mp[1][i + 1] == 'o':
        cnt += 1
    if i != n - 1 and mp[1][i] == 'o' and mp[0][i + 1] == 'o':
        cnt += 1
for i in range(k):
    l = input().strip()
    if l == 'Q':
        print("Jebb" if cnt == 0 else "Neibb")
    else:
        _, x, y = l.split()
        x, y = int(x) - 1, int(y) - 1
        if mp[x][y] == 'o':
            for dy in [-1, 0, 1]:
                if y + dy < 0 or y + dy >= n:
                    continue
                if mp[1 - x][y + dy] == 'o':
                    cnt -= 1
            mp[x][y] = '.'
        else:
            for dy in [-1, 0, 1]:
                if y + dy < 0 or y + dy >= n:
                    continue
                if mp[1 - x][y + dy] == 'o':
                    cnt += 1
            mp[x][y] = 'o'


