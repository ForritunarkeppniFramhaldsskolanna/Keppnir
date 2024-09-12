#!/usr/bin/python3
import sys
import random

try:
    sys.set_int_max_str_digits(0)
except Exception: # in case kattis does not have 3.10
    pass

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
n = random.choice([random.randint(max_n // 2, max_n), max_n])
n = max(n, 2)
extra = None
if len(sys.argv) >= 3:
    extra = sys.argv[2]

pre = "".join([str(random.randint(1, 9)) for i in range(5)])
post = "".join([str(random.randint(0, 9)) for i in range(n)])

if extra == "zero":
    pre = "0"
    if post[0] >= '5':
        post = '4' + post[1:]

digs = pre + post
m = random.randint(1, len(digs) - 1)

if extra == "nice":
    m = max(m, len(pre) + 1)

digs2 = digs[:m]
shf = False

if random.randint(1, 3) != 1:
    initlen = len(digs2)
    digs2 = int(digs2)
    nozerolen = len(str(digs2))
    if digs[m] >= '5' and digs2 != 9:
        digs2 += 1
    digs2 = str(digs2)
    if len(digs2) != nozerolen:
        initlen += 1
        shf = True
    d = initlen - len(digs2)
    digs2 = ("0" * d) + digs2

d = len(pre)
if shf:
    d += 1

while len(digs2) < d:
    digs2 += "0"

pre2, post2 = digs2[:d], digs2[d:]
if len(post2) == 0:
    post2 = "0"

post = post.rstrip("0")
post2 = post2.rstrip("0")
if post == "":
    post = "0"
if post2 == "":
    post2 = "0"

if len(post) == len(post2):
    post = post + "7"

print(pre + "." + post)
print(pre2 + "." + post2)

