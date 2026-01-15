#!/usr/bin/python3
import sys
import re
import datetime

max_n = 1000
ordfix = "????"

exec(sys.argv[1])  # max_n
exec(sys.argv[2])  # ordfix

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)

assert 1 <= n <= max_n

ids = set()

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[a-zA-Z ]+, [0-9]+, [a-zA-Z\- ]+, [0-9\-]+\n$", line)
    nam, idnum, typ, date = line.strip().split(", ")
    assert nam[0] != " "
    assert nam[-1] != " "
    assert 1 <= len(nam) <= 32
    assert len(idnum) == 8
    assert idnum not in ids
    ids.add(idnum)
    if " - " not in typ:
        assert typ == "Annad"
    else:
        assert typ.count(" - ") == 1
        over, under = typ.split(" - ")
        if over == "Skrimsli":
            assert under in ["Venjulegt", "Ahrifa", "Bodunar", "Samruna", "Samstillt", "Thaeo", "Penduls", "Tengis"]
        elif over == "Galdur":
            assert under in ["Venjulegur", "Bunadar", "Svida", "Samfelldur", "Bodunar", "Hradur"]
        elif over == "Gildra":
            assert under in ["Venjuleg", "Samfelld", "Mot"]
        else:
            assert False
    chk = datetime.date.fromisoformat(date)
    assert 2000 <= chk.year <= 2025

line = sys.stdin.readline()
ch = "(nafn|id|flokkur|dagsetning)"
assert re.match("^{} {} {} {}\n$".format(ch, ch, ch, ch), line)
ords = list(line.split())
assert len(set(ords)) == 4

assert len(ordfix) == 4

for i in range(4):
    if ordfix[i] == "n":
        assert ords[i] == "nafn"
    if ordfix[i] == "f":
        assert ords[i] == "flokkur"
    if ordfix[i] == "i":
        assert ords[i] == "id"
    if ordfix[i] == "d":
        assert ords[i] == "dagsetning"

assert not sys.stdin.read()
sys.exit(42)
