#!/usr/bin/python3
s = input()
t = input()

h1,m1 = map(int, s.split(':'))
h2,m2 = map(int, t.split(':'))

print((h2-h1)*60 + (m2-m1))
