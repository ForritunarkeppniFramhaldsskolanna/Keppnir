#!/usr/bin/python3
import sys, random, math

class StringMaker:
    def __init__(self):
        self.l = 1
        self.c = ['G']
    def get_next(self):
        ret = ''.join(self.c)
        for i in range(len(self.c)):
            if self.c[i] == 'Z':
                self.c[i] = 'A'
            else:
                self.c[i] = chr(ord(self.c[i]) + 1)
                return ret
        self.l += 1
        self.c = ['A' for i in range(self.l)]
        return ret

cyc = eval(sys.argv[1])
n = eval(sys.argv[2])

if cyc:
    print(n)
    print("A", 0)
    print("B", 0)
    print("C", 2, "A", "A")
    print("D", 3, "B", "B", "B")
    print("E", 6, "A", "A", "C", "D", "D", "A")
    print("F", 0)
    maker = StringMaker()
    for i in range(n - 6):
        print(maker.get_next(), 0)
else:
    print(n)
    print("A", 0)
    print("B", 0)
    print("C", 2, "A", "A")
    print("D", 3, "B", "B", "B")
    print("E", 3, "C", "D", "D")
    maker = StringMaker()
    for i in range(n - 5):
        print(maker.get_next(), 0)
