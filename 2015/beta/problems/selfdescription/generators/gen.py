ts = [
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    20,
    25,
    41,
    52,
    63,
    74,
    86,
    99,
    100
]

for i, t in enumerate(ts):

    with open('%02d.in' % i, 'w') as f:
        f.write('%d\n' % t)

