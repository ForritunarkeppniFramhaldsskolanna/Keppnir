import sys
from random import randint
from random import shuffle

minn, maxn, mins, maxs, numans, shuff = map(int, sys.argv[1:7])
names = []
with open("names.txt") as f:
    for line in f.readlines():
        line = line.strip()
        if len(line) <= 1 or len(line.split()) > 1:
            continue
        if all(ord('a') <= ord(x) <= ord('z') or ord('A') <= ord(x) <= ord('Z') for x in line):
            names.append(line)

if shuff:
    shuffle(names)

n = randint(minn, maxn)
s = randint(mins, maxs)
sys.stdout.write("%d %d\n" % (n, s))
correct = [chr(ord('A') + randint(0, numans-1)) for x in range(n)]
sys.stdout.write(' '.join(correct))
sys.stdout.write('\n')
for i in range(s):
    sys.stdout.write("%s\n" % names[i])
    chance = randint(1,100)
    answers = [chr(ord('A') + randint(0, numans-1)) if randint(0,100) >= chance else correct[x] for x in range(n)]
    sys.stdout.write(' '.join(answers))
    sys.stdout.write('\n')
