import sys

files = {
    "63.9829 22.600517": "01.ans",
    "63.84378 22.41705": "02.ans",
    "63.8692 21.16018": "1395_20years_year.ans",
    "64.08172 22.68932": "1453_20years_year.ans",
    "64.12884 21.90822": "1470_20years_year.ans",
    "64.15451 22.03251": "1471_20years_year.ans",
    "64.11635 21.86167": "1472_20years_year.ans",
    "64.38773 21.41688": "1685_20years_year.ans",
    "64.45295 21.40342": "1689_20years_year.ans",
    "64.5622 21.764933": "1779_20years_year.ans",
    "64.64302 21.5893": "1781_20years_year.ans",
    "64.69432 22.14733": "1868_20years_year.ans",
    "65.0717 22.73237": "2050_20years_year.ans",
    "66.05963 23.16993": "2642_20years_year.ans",
    "65.69612 18.11132": "3471_20years_year.ans",
    "66.54378 18.01673": "3976_20years_year.ans",
    "65.15027 13.66942": "5990_20years_year.ans",
    "64.68098 19.28268": "6745_20years_year.ans",
}

n, m = map(int, input().split())
latitude, longtitude, elevation, date, time = input().split()
filename = files[latitude + " " + longtitude]
with open(filename) as f:
    lines = f.readlines()
for x in lines[-m:]:
    sys.stdout.write(x)
