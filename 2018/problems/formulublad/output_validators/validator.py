import sys

formulas = []
with open(sys.argv[1], 'r') as f:
    n, L = map(int, f.readline().split())
    for i in range(n):
        a,b = map(int, f.readline().split())
        formulas.append((a,b))

with open(sys.argv[2], 'r') as f:
    num, ans = map(int, f.readline().split())

def WA():
    sys.exit(43)

try:
    k, M = map(int, sys.stdin.readline().split())
except ValueError:
    WA() # Output was not integers

if k > n:
    WA()

if M != ans:
    WA()

line = sys.stdin.readline()
splt = line.split()
if len(splt) != k:
    WA()

weight = 0
sm = 0
for ind in splt:
    try:
        ind = int(ind)
    except ValueError:
        WA()
    try:
        weight += formulas[ind][0]
        sm += formulas[ind][1]
    except IndexError:
        WA()

if weight > L:
    WA()

if sm != ans:
    WA()

sys.exit(42)
