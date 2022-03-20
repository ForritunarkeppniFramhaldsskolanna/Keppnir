#!/usr/bin/python3
import sys
import random
from string import ascii_lowercase

random.seed(int(sys.argv[-1]))

max_u = eval(sys.argv[1])
max_k = eval(sys.argv[2])
max_name = eval(sys.argv[3])

u = random.randint(1, max_u)
k = random.randint(1, max_k)

print(u, k)

legal = [c for c in ascii_lowercase] + ['_']
def rand_name(n):
    res = []
    for i in range(n):
        res.append(random.choice(legal))
    return "".join(res)

ex_u = max_name - u
ex_k = max_name - k

h = ex_u // u + 1
n = ex_k // k + 1

rec_name_set = set()
rec_name_lst = []
ing_name_set = set()
ing_name_lst = []

for i in range(u):
    nam = rand_name(20)
    while nam in rec_name_set:
        nam = rand_name(20)
    rec_name_set.add(nam)
    rec_name_lst.append(nam)
    print(nam)
    print(h)
    cur_ing_set = set()
    for j in range(h):
        ing = None
        while ing is None or ing in cur_ing_set:
            if len(ing_name_set) > 0 and random.randint(1, 2) == 1:
                ing = random.choice(ing_name_lst)
            else:
                ing = rand_name(20)
        if ing not in ing_name_set:
            ing_name_set.add(ing)
            ing_name_lst.append(ing)
        x = random.randint(1, 500)
        cur_ing_set.add(ing)
        print(ing, x)

for i in range(k):
    print(n)
    for j in range(n):
        nam = random.choice(rec_name_lst)
        x = random.randint(1, 500)
        print(nam, x)

