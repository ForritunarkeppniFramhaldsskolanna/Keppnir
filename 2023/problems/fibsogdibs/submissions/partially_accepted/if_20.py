#!/usr/bin/python3
a, b = map(int, input().split())
n = int(input())

if n == 0:
    print(a, b)
elif n == 1:
    print(1*a+1*b, 1*a+2*b)
elif n == 2:
    print(2*a+3*b, 3*a+5*b)
elif n == 3:
    print(5*a+8*b, 8*a+13*b)
elif n == 4:
    print(13*a+21*b, 21*a+34*b)
elif n == 5:
    print(34*a+55*b, 55*a+89*b)
elif n == 6:
    print(89*a+144*b, 144*a+233*b)
elif n == 7:
    print(233*a+377*b, 377*a+610*b)
elif n == 8:
    print(610*a+987*b, 987*a+1597*b)
elif n == 9:
    print(1597*a+2584*b, 2584*a+4181*b)
elif n == 10:
    print((4181*a+6765*b) % (10**9+7), (6765*a+10946*b) % (10**9+7))
