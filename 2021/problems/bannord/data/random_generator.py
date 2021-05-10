import sys
import random
import re

random.seed(int(sys.argv[-1]))

s = int(sys.argv[1])
m = int(sys.argv[2])
p = int(sys.argv[3])

a = []
ss = []
l = 26
for i in range(26):
    a.append(chr(ord('a') + i))
random.shuffle(a)
for i in range(s):
    ss.append(a[i])
print("".join(ss))
a = []
for _ in range(m):
    y = random.randint(0, 99)
    if y < p:
        x = 26
    else:
        x = random.randint(0, 25)
    while x == 26 and l == x: x = random.randint(0, 26)
    l = x
    if x != 26: a.append(chr(ord('a') + x))
    else: a.append(' ')
print(re.sub(' +', ' ', "".join(a)).strip())
