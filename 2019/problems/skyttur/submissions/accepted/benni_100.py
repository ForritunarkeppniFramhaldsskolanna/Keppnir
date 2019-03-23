#!/usr/bin/python3
n = int(input())
a = input()
b = input()
ne = ""
for x in range(n):
    if a[x] == b[x]:
        ne += "0"
    else:
        ne += "1"
print(ne)
