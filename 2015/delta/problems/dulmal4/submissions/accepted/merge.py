import itertools
import sys
import string
import random

n = int(raw_input())

words = []
for i in range(n):
    words.append(raw_input())

length = 1
while True:

    valid = [ [] for w in words ]

    for j in range(1, length):
        cnt = 0
        for i in range(0, length, j):
            cnt += 1

        for i in range(len(words)):
            if len(words[i]) == cnt:
                valid[i].append(j)

    for ass in itertools.product(*valid):
        s = ['_']*length
        ok = True
        for i in range(len(words)):

            w = words[i]
            for j in range(len(w)):
                at = j*ass[i]
                if s[at] == '_' or s[at] == w[j]:
                    s[at] = w[j]
                else:
                    ok = False
                    # break

            # if not ok:
            #     break

        if ok:
            print(''.join(random.choice(string.ascii_lowercase) if c == '_' else c for c in s))
            sys.exit(0)


    length += 1

