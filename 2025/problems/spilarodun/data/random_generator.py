#!/usr/bin/python3
import sys
import string
import random
import datetime
import itertools

random.seed(int(sys.argv[-1]))

max_n = int(sys.argv[1])
ords = int(sys.argv[2])
if ords == -1:
    ords = random.randint(0, 23)
day_range = int(sys.argv[3])
names = set()

chars = list(string.ascii_letters) + [" "]


def card_name():
    if len(names) > 0 and random.randint(1, 3) == 1:
        return random.choice(list(names))
    l = random.randint(1, 32)
    res = []
    for i in range(l):
        if i == 0 or i == l - 1:
            res.append(random.choice(string.ascii_letters))
        else:
            res.append(random.choice(chars))
    s = "".join(res)
    names.add(s)
    return s


def random_date(start, end):
    delta = end - start
    int_delta = (delta.days * 24 * 60 * 60) + delta.seconds
    random_second = random.randrange(int_delta)
    return start + datetime.timedelta(seconds=random_second)


fst_date = datetime.date.fromisoformat("2000-01-01")
lst_date = fst_date + datetime.timedelta(days=day_range)


def random_id():
    res = [random.choice(string.digits) for _ in range(8)]
    return "".join(res)


flk = set()
for s in ["Venjulegt", "Ahrifa", "Bodunar", "Samruna", "Samstillt", "Thaeo", "Penduls", "Tengis"]:
    flk.add("Skrimsli - " + s)
for s in ["Venjulegur", "Bunadar", "Svida", "Samfelldur", "Bodunar", "Hradur"]:
    flk.add("Galdur - " + s)
for s in ["Venjuleg", "Samfelld", "Mot"]:
    flk.add("Gildra - " + s)
flk.add("Annad")
flk = list(flk)

n = random.choice([random.randint(max_n // 2, max_n), max_n])
n = max(n, 1)

print(n)

ids = set()

for _ in range(n):
    nam = card_name()
    cur_id = random_id()
    while cur_id in ids:
        cur_id = random_id()
    ids.add(cur_id)
    typ = random.choice(flk)
    dat = random_date(fst_date, lst_date).isoformat()
    print(nam + ", " + cur_id + ", " + typ + ", " + dat)

shuf = ["nafn", "id", "flokkur", "dagsetning"]
shufs = list(itertools.permutations(shuf))
print(" ".join(shufs[ords]))
