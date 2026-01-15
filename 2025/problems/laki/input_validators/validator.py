#!/usr/bin/python3
import sys
import re

group = "S"

exec(sys.argv[1])  # group

line = sys.stdin.readline()

chemicals = [
    "H",
    "He",
    "Li",
    "Be",
    "B",
    "C",
    "N",
    "O",
    "F",
    "Ne",
    "Na",
    "Mg",
    "Al",
    "Si",
    "P",
    "S",
    "Cl",
    "Ar",
    "K",
    "Ca",
    "Sc",
    "Ti",
    "V",
    "Cr",
    "Mn",
    "Fe",
    "Co",
    "Ni",
    "Cu",
    "Zn",
    "Ga",
    "Ge",
    "As",
    "Se",
    "Br",
    "Kr",
    "Rb",
    "Sr",
    "Y",
    "Zr",
    "Nb",
    "Mo",
    "Tc",
    "Ru",
    "Rh",
    "Pd",
    "Ag",
    "Cd",
    "In",
    "Sn",
    "Sb",
    "Te",
    "I",
    "Xe",
    "Cs",
    "Ba",
    "La",
    "Ce",
    "Pr",
    "Nd",
    "Pm",
    "Sm",
    "Eu",
    "Gd",
    "Tb",
    "Dy",
    "Ho",
    "Er",
    "Tm",
    "Yb",
    "Lu",
    "Hf",
    "Ta",
    "W",
    "Re",
    "Os",
    "Ir",
    "Pt",
    "Au",
    "Hg",
    "Tl",
    "Pb",
    "Bi",
    "Po",
    "At",
    "Rn",
    "Fr",
    "Ra",
    "Ac",
    "Th",
    "Pa",
    "U",
    "Np",
    "Pu",
    "Am",
    "Cm",
    "Bk",
    "Cf",
    "Es",
    "Fm",
    "Md",
    "No",
    "Lr",
    "Rf",
    "Db",
    "Sg",
    "Bh",
    "Hs",
    "Mt",
    "Ds",
    "Rg",
    "Cn",
    "Nh",
    "Fl",
    "Mc",
    "Lv",
    "Ts",
    "Og",
]
to_join = ["("]
for ch in chemicals:
    to_join.append(ch)
    to_join.append("|")
to_join.pop()
to_join.append(")")
chem_reg = "".join(to_join)

num = "0|[1-9][0-9]*"
nonz = "[1-9][0-9]*"
cmplx = "({}) \\+ ({})i".format(num, num)
hexnum = "0x[0-9a-f]+"
strng = '"[a-zA-Z0-9]*"'
vector = "\\({}(, {})*\\)".format(num, num)
numset = "(\\{(" + num + ")(, (" + num + "))*\\})|(\\{\\})"
log = "log\\(({})\\)".format(num)
mod = "({}) mod ({})".format(num, nonz)
mayan_digs = "𝋠𝋡𝋢𝋣𝋤𝋥𝋦𝋧𝋨𝋩𝋪𝋫𝋬𝋭𝋮𝋯𝋰𝋱𝋲𝋳"
mayan_num = "{}|[{}][{}]*".format(mayan_digs[0], mayan_digs[1:], mayan_digs)
text = "[a-z]+"

regs = {
    "A": num,
    "B": strng,
    "C": hexnum,
    "D": cmplx,
    "E": log,
    "F": numset,
    "G": chem_reg,
    "H": mayan_num,
    "I": mod,
    "J": text,
}

accs = 0
for k, v in regs.items():
    reg = "^(" + v + ") \\+ (" + v + ")\n$"
    matches = re.match(reg, line)
    if matches:
        accs += 1
        assert ord(k) <= ord(group)

assert accs == 1

assert not sys.stdin.read()
sys.exit(42)
