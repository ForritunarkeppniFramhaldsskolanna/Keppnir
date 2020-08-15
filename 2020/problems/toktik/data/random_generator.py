import sys
import random

import string

max_n = eval(sys.argv[1])
n = max_n
# n = random.randint(1,max_n)
persons = random.randint(1,n)

def randomString(stringLength=10):
    """Generate a random string of fixed length """
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(stringLength))

ls = []
for x in range(persons):
    ls.append(randomString(random.randint(10,20)))

videos = []
for x in range(n):
    videos.append([ls[random.randint(0,len(ls)-1)], random.randint(1,10**4)])

d = {}
for x in ls:
    if x not in d:
        d[x] = 0

mx = 0
for x in videos:
    d[x[0]] += x[1]
    mx = max(mx, d[x[0]])
nm = 0
for x in d:
    if d[x] == mx:
        nm  += 1

if nm != 1:
    name = ""
    for x in d:
        if d[x] == mx:
            name = x
            break
    for x in range(len(videos)):
        if videos[x][0] == name:
            videos[x][1] += 1
            break
print(n)
for x in videos:
    print(x[0] + " " + str(x[1]))


