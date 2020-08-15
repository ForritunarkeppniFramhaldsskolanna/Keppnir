n,m = [int(x) for x in raw_input().split()]
grid = []
# to = {}
to = [ [ [ None for k in range(34) ] for j in range(m) ] for i in range(n) ]

direction = {}
direction['v'] = (1,0)
direction['>'] = (0,1)
direction['<'] = (0,-1)
direction['^'] = (-1,0)

for x in range(n):
    grid.append(raw_input())
    for y in range(m):
        to[x][y][0] = (x + direction[grid[x][y]][0], y + direction[grid[x][y]][1])

for z in range(1,34):
    for x in range(n):
        for y in range(m):
            at = to[x][y][z-1]
            new_at = to[at[0]][at[1]][z-1]
            to[x][y][z] = new_at

q = int(input())
for i in range(q):
    x,y,k = [int(j) for j in raw_input().split()]
    x -= 1
    y -= 1
    at = (x,y)
    for j in range(33,-1,-1):
        t = 2**j
        if t <= k:
            at = to[at[0]][at[1]][j]
            k -= t
    print(str(at[0]+1) + " " + str(at[1]+1))
