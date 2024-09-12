#!/usr/bin/python3
n = int(input())
res = ""
for j in range(n + 1):
    res += " "
res += "x\n"
for i in range(n):
    for j in range(n - i):
        res += " "
    res += "/"
    for j in range(2 * i + 1):
        res += " "
    res += "\\\n"
res += "x"
for j in range(2 * n + 1):
    res += " "
res += "x\n"
for i in reversed(range(n)):
    for j in range(n - i):
        res += " "
    res += "\\"
    for j in range(2 * i + 1):
        res += " "
    res += "/\n"
for j in range(n + 1):
    res += " "
res += "x"
print(res)
