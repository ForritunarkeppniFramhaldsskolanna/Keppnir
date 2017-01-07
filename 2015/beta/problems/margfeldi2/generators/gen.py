import random

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
    12,
    13,
    14,
    'randomvalid',
    'randomvalid',
    'randomvalid',
    'randomvalid',
    'randomvalid',
    'randomvalid',
    'randomvalid',
    'randomvalid',
    'randomvalid',
    'randomvalid',
    'randomvalid',
    'random',
    'random',
    'random',
    'random',
    'random',
    'random',
    'random',
    'random',
    'random',
]

for t, x in enumerate(ts):

    if type(x) is str:
        if x == 'random':
            x = random.randint(0,1000000000)
        elif x == 'randomvalid':
            while True:
                x = random.randint(0,1000000000)
                tmp = x
                for i in range(2,10):
                    while tmp % i == 0:
                        tmp //= i
                if tmp > 1:
                    continue
                break
            # print('Found ', x)
        else:
            assert False

    with open('%02d.in' % t, 'w') as f:
        f.write('%d\n' % x)

