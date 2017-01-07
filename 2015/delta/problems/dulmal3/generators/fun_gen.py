import random
import string

words = set(open('/usr/share/dict/american-english', 'r').read().strip().split('\n'))

n = 10
while True:
    s = ''.join( random.choice(string.ascii_lowercase) for _ in range(n) )
    found = []
    for k in range(1, len(s)+1):
        cur = ''
        for i in range(0, len(s), k):
            cur += s[i]

        if len(cur) < 4:
            continue

        if cur in words:
            found.append(cur)

    if len(found) <= 1:
        continue

    print(len(found), s)
    for w in found:
        print(w)

