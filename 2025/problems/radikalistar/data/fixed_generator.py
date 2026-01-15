#!/usr/bin/python3
import sys

ind = int(sys.argv[1])

inps = [
    "1 1\nm 1",
    "10 1\nr 10 1 3 4 7 8 2 10 5 6 9",
    "5 1\ns",
    "1 1\nr 1 1",
    "7 1\nm 3",
    "2 1\ns",
    "3 1\nr 2 1 2",
    "9 1\nm 7",
]

if ind <= 7:
    print(inps[ind])
