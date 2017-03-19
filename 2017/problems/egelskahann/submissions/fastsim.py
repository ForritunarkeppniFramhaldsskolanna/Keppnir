n = int(input())

nxt = [(i+1)%n for i in range(n)]

i = 0
while i != nxt[i]:
    nxt[i] = nxt[nxt[i]]
    i = nxt[i]

print(i+1)
