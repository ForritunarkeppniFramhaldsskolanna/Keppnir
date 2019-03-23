import sys
from random import randint
import random
import string

# Type of testcase:
#   1: small
#   2: large
tc = int(sys.argv[1])


r = -1
c = -1
n = -1

if tc == 1:
    r = randint(2,100)
    c = randint(2,100)
    n = r*c
    while r*c > 100:
        r = randint(2,100)
        c = randint(2,100)
        n = r*c
if tc == 2:
    r = randint(2,10000)
    c = randint(2,10000)
    n = r*c
    while r*c > 10000:
        r = randint(2,10000)
        c = randint(2,10000)
        n = r*c

sys.stdout.write("%s %s %s\n" % (n, r, c))
classroom = [["".join([random.choice(string.ascii_lowercase) for i in range(randint(15, 20))]) for col in range(c)] for row in range(r)]
roll_call = []
for line in classroom:
    sys.stdout.write(" ".join(line) + "\n")
    flipped = bool(random.getrandbits(1))
    if flipped:
        roll_call.extend(line[::-1])
    else:
        roll_call.extend(line)


for name in roll_call:
    print(name)