#!/usr/bin/python3

import math

d = int(input())
a = int(input())
b = int(input())
h = int(input())

mahjong = ((d / 2) ** 2) * math.pi
trapizza = ((a + b) / 2) * h

if trapizza > mahjong:
    print("Trapizza!")
elif mahjong > trapizza:
    print("Mahjong!")
else:
    print("Jafn storar!")

