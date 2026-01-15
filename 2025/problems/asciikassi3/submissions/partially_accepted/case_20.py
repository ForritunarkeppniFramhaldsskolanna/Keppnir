#!/usr/bin/python3
h, w, d = map(int, input().strip().split())
if h == 1 and w == 1 and d == 1:
    print("+")
if h == 1 and w == 1 and d == 2:
    print(" +\n+")
if h == 1 and w == 1 and d == 3:
    print("  +\n /\n+")
if h == 1 and w == 2 and d == 1:
    print("++")
if h == 1 and w == 2 and d == 2:
    print(" ++\n++")
if h == 1 and w == 2 and d == 3:
    print("  ++\n //\n++")
if h == 1 and w == 3 and d == 1:
    print("+-+")
if h == 1 and w == 3 and d == 2:
    print(" +-+\n+-+")
if h == 1 and w == 3 and d == 3:
    print("  +-+\n / /\n+-+")
if h == 2 and w == 1 and d == 1:
    print("+\n+")
if h == 2 and w == 1 and d == 2:
    print(" +\n++\n+")
if h == 2 and w == 1 and d == 3:
    print("  +\n /+\n+/\n+")
if h == 2 and w == 2 and d == 1:
    print("++\n++")
if h == 2 and w == 2 and d == 2:
    print(" ++\n+++\n++")
if h == 2 and w == 2 and d == 3:
    print("  ++\n /++\n++/\n++")
if h == 2 and w == 3 and d == 1:
    print("+-+\n+-+")
if h == 2 and w == 3 and d == 2:
    print(" +-+\n++++\n+-+")
if h == 2 and w == 3 and d == 3:
    print("  +-+\n /+x+\n+x+/\n+-+")
if h == 3 and w == 1 and d == 1:
    print("+\n|\n+")
if h == 3 and w == 1 and d == 2:
    print(" +\n+|\n|+\n+")
if h == 3 and w == 1 and d == 3:
    print("  +\n /|\n+ +\n|/\n+")
if h == 3 and w == 2 and d == 1:
    print("++\n||\n++")
if h == 3 and w == 2 and d == 2:
    print(" ++\n++|\n|++\n++")
if h == 3 and w == 2 and d == 3:
    print("  ++\n /x|\n++++\n|x/\n++")
if h == 3 and w == 3 and d == 1:
    print("+-+\n| |\n+-+")
if h == 3 and w == 3 and d == 2:
    print(" +-+\n+x+|\n|+x+\n+-+")
if h == 3 and w == 3 and d == 3:
    print("  +-+\n /|/|\n+-+-+\n|/|/\n+-+")
