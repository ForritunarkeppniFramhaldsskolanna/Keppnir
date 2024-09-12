#!/usr/bin/python3

import random, sys

random.seed(int(sys.argv[-1]))

class StringMaker:
    def __init__(self):
        self.l = 1
        self.c = ['a']
    def get_next(self):
        ret = ''.join(self.c)
        for i in range(len(self.c)):
            if self.c[i] == 'Z':
                self.c[i] = 'a'
            else:
                self.c[i] = chr(ord(self.c[i]) + 1)
                if self.c[i] == '{':
                    self.c[i] = 'A'
                return ret
        self.l += 1
        self.c = ['a' for i in range(self.l)]
        return ret

max_n = int(sys.argv[1])
max_q = int(sys.argv[2])
par = eval(sys.argv[3])
ties = eval(sys.argv[4])
given_ind = int(sys.argv[5])

n = random.choice([random.randint(max_n // 2, max_n), max_n])
n = max(n, 1)
q = random.choice([random.randint(max_q // 2, max_q), max_q])
q = max(q, 1)
print(n, q)

mx_score = [5, 10 ** 3, 10 ** 9][given_ind % 3]
if not ties:
    mx_score = 10 ** 9

maker = StringMaker()
names = [maker.get_next() for _ in range(2 * n + 1000)]
random.shuffle(names)
names = names[:n]
print(*names)

for qi in range(q):
    if not ties and qi == 0:
        namecp = names[:]
        random.shuffle(namecp)
        out = []
        for i in range(n):
            out.append(namecp[i])
            if random.randint(1, 2) == 1:
                out.append(random.randint(1, mx_score))
            else:
                out.append(random.randint(-mx_score, -1))
        print("!", n, *out)
    elif par or random.randint(1, 2) == 1:
        print("?", random.choice(names))
    else:
        k = random.randint(1, 10 ** 6 // 4 // q)
        if k > n:
            k = random.randint(1, n)
        picks = random.sample(names, k)
        out = []
        for pick in picks:
            out.append(pick)
            if random.randint(1, 2) == 1:
                out.append(random.randint(1, mx_score))
            else:
                out.append(random.randint(-mx_score, -1))
        print("!", k, *out)
