#!/usr/bin/python3
import sys, random, math

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
max_q = eval(sys.argv[2])
exists = eval(sys.argv[3])
unique = eval(sys.argv[4])
order = eval(sys.argv[5])

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

author_maker = StringMaker()
title_maker = StringMaker()
n = random.choice([random.randint(max_n // 2, max_n), max_n])
q = random.choice([random.randint(max_q // 2, max_q), max_q])
titles = [title_maker.get_next() for _ in range(n)]
authors = [author_maker.get_next() for _ in range(n)]
random.shuffle(titles)
random.shuffle(authors)
print(n, q)
books = []
for i in range(n):
    if not unique and random.randint(1, 4) == 1:
        author = random.choice(authors)
        books.append((author, titles[i]))
    else:
        books.append((authors[i], titles[i]))

if order:
    books.sort()
for (author, title) in books:
    print(title + ",", author)

for _ in range(q):
    if (len(books) == 0) or (exists == -1) or (exists == 0 and random.randint(1, 10) == 1):
        print(title_maker.get_next())
    else:
        print(random.choice(books)[1])
