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

formula = line.replace('EDA', 'or').replace('OG', 'and').replace('!', 'not ')
for it in range(1000):
    if eval(formula, { k : random.choice([True,False]) for k in vs  }):
        print('Jebb')
        sys.exit(0)

print('Neibb')

