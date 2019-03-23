import sys
grid = []
with open(sys.argv[1], 'r') as f:
    n,m = [int(x) for x in f.readline().split()]
    for x in range(n):
        grid.append(f.readline().strip())

def WA():
    sys.exit(43)

ans = []
for x in range(len(grid)):
    for y in range(len(grid[x])):
        if grid[x][y] == '*':
            ans.append((x+1,y+1))
ans = sorted(ans)
try:
    k = int(sys.stdin.readline())
    if k != len(ans):
        WA()
    ans2 = []
    for x in range(k):
        a,b = [int(y) for y in sys.stdin.readline().split()]
        ans2.append((a,b))

    ans2 = sorted(ans2)
    for y in range(k):
        if ans[y] != ans2[y]:
            WA()
except Exception:
    WA() # Output was not integers


sys.exit(42)
