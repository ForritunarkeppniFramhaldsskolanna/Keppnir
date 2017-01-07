import sys
sys.setrecursionlimit(9999999)

n = int(raw_input())
names = [ raw_input() for i in range(n) ]
m = int(raw_input())
forbidden = [ raw_input().split() for i in range(m) ]

adj = {}
for name in names:
    adj.setdefault(name, [])

for a, b in forbidden:
    adj[a].append(b)
    adj[b].append(a)

walter = {}
ok = True

def dfs(cur):
    global ok

    for nxt in adj[cur]:

        if nxt in walter:
            if walter[cur] == walter[nxt]:
                ok = False

        else:
            walter[nxt] = not walter[cur]
            dfs(nxt)


for name in names:
    if name not in walter:
        walter[name] = False
        dfs(name)

if ok:

    print(' '.join( name for name in names if walter[name] ))
    print(' '.join( name for name in names if not walter[name] ))

else:
    print('impossible')

