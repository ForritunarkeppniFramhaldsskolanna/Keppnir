import sys
found = False

for clause in sys.stdin.readline().strip().split(' EDA '):
    t = set()
    f = set()
    for v in clause.strip('()').split(' OG '):
        if v[0] == '!':
            f.add(v[1:])
        else:
            t.add(v)

    if len(t & f) == 0:
        found = True

if found:
    print('Jebb')
else:
    print('Neibb')

