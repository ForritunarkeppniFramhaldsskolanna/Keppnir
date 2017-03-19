import random
import sys
line = sys.stdin.readline().strip()

vs = set(
    line.replace('EDA', ' ')
        .replace('OG', ' ')
        .replace('!', ' ')
        .replace('(', ' ')
        .replace(')', ' ')
        .split())
vs = list(vs)

formula = line.replace('EDA', 'or').replace('OG', 'and').replace('!', 'not ')

assert len(vs) <= 15
for ass in range(2**len(vs)):
    if eval(formula, { k : ((ass & (1<<i)) != 0) for i, k in enumerate(vs) }):
        print('Jebb')
        sys.exit(0)

print('Neibb')

