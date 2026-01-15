import sys
import math

h, w = map(int, sys.stdin.readline().strip().split())
mp = [sys.stdin.readline().strip() for _ in range(h)]
s_x, s_y = -1, -1
for i in range(h):
    for j in range(w):
        if mp[i][j] == "S":
            s_x, s_y = i, j
bst = math.inf
for i in range(h):
    for j in range(w):
        if mp[i][j] != "G":
            continue
        bst = min(bst, abs(i - s_x) + abs(j - s_y))
if bst == math.inf:
    print("thralatlega nettengdur")
else:
    print(bst)
