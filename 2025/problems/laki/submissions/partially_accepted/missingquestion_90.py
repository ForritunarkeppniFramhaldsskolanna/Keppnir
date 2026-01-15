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
    "Ds ",
    "Rg ",
    "Cn ",
    "Nh",
    "Fl",
    "Mc",
    "Lv",
    "Ts",
    "Og",
]

digs = "𝋠𝋡𝋢𝋣𝋤𝋥𝋦𝋧𝋨𝋩𝋪𝋫𝋬𝋭𝋮𝋯𝋰𝋱𝋲𝋳"

questions = {
    "tragedy + time": "comedy",
    "repetiton + repetition": "learning",
    "fire + water": "steam",
    "red + blue": "purple",
    "throat + potato": "danish",
    "kattis + program": "verdict",
    "problem + solution": "AC",
    "contest + geometry": "WA",
    "nonsense + annoyance": "this problem",
}


def gcd_extended(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = gcd_extended(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y


def from_mayan(s):
    global digs
    sm = 0
    for c in s:
        sm *= 20
        sm += digs.index(c)
    return sm


def to_mayan(x):
    global digs
    if x == 0:
        return digs[0]
    res = []
    while x > 0:
        res.append(digs[x % 20])
        x //= 20
    return "".join(res[::-1])


inp = input().strip()
a, b = inp.split(" + ", 1)

if '"' in inp:
    print(eval(inp))
elif "{" in inp:
    a, b = set(eval(a)), set(eval(b))
    l = sorted(list(a.union(b)))
    res = str(l)
    print("{" + res[1:-1] + "}")
elif inp[0] in digs:
    a = from_mayan(a)
    b = from_mayan(b)
    print(to_mayan(a + b))
elif "mod" in inp:
    h1, h2 = inp.split(" + ")
    a1, n1 = map(int, h1.split(" mod "))
    a2, n2 = map(int, h2.split(" mod "))
    _, m1, m2 = gcd_extended(n1, n2)
    x = a1 * m2 * n2 + a2 * m1 * n1
    m = n1 * n2
    print("{} mod {}".format(x % m, m))
elif len(inp) >= 3 and inp[:3] == "log":
    a = int(a[4:-1])
    b = int(b[4:-1])
    print("log({})".format(a * b))
elif len(inp) >= 2 and inp[:2] == "0x":
    print("0x{:x}".format(int(a, 16) + int(b, 16)))
elif inp.count("+") > 1:
    x, y, z, w = inp.split("+")
    x, y, z, w = x.strip(), y.strip(), z.strip(), w.strip()
    x, y, z, w = int(x), int(y[:-1]), int(z), int(w[:-1])
    print("{} + {}i".format(x + z, y + w))
elif inp.strip() in questions:
    print(questions[inp.strip()])
elif all(c not in inp for c in "0123456789"):
    x = chemicals.index(a) + 1
    y = chemicals.index(b) + 1
    print(chemicals[x + y - 1])
else:
    print(eval(inp))
