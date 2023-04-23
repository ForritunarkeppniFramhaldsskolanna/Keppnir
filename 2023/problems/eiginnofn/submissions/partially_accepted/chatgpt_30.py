#!/usr/bin/python3
n = int(input())
residents = {}
for i in range(n):
    names = input().split()
    if len(names) == 1:
        residents[names[0]] = True
    else:
        residents[names[0]] = names[1]

m = int(input())
for i in range(m):
    name = input()
    if name in residents:
        if residents[name] == True:
            print("Jebb")
        else:
            print("Neibb en " + residents[name] + " er heima")
    else:
        print("Neibb")

