import sys
import random

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
method = sys.argv[2]

if method == 'onlymoney':
    print(''.join( random.choice('.pog') for i in range(n) ))
elif method == 'random':
    print(''.join( random.choice('.pogPOG') for i in range(n) ))
elif method == 'randompog':
    print(''.join( random.choice('.pogpogPOG') for i in range(n) ))
elif method == 'randomvalid':
    S = []
    res = ''
    for i in range(n):
        if random.randint(0,1) == 1 and S:
            take = random.randint(0, len(S)-1)
            res += S[take].upper()
            S = S[:take]
        else:
            cur = random.choice('pog')
            S.append(cur)
            res += cur
    print(res)

