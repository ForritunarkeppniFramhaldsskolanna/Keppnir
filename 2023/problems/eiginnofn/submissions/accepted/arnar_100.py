#!/bin/python3
n = int(input())
names = {}
for i in range(n):
    line = input().split()
    if len(line) == 1:
        names[line[0]] = ""
    else:
        names[line[0]] = line[1]

m = int(input())
for i in range(m):
    first_name = input()
    if first_name in names:
        second_name = names[first_name]
        if second_name == "":
            print("Jebb")
        else:
            print("Neibb en {} {} er heima".format(first_name, second_name))
    else:
        print("Neibb")

