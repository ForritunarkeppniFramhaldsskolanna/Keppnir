#!/usr/bin/python3
n = int(input())
parts = [input() for i in range(n)]
msg = ""
for part in parts[::-1]:
    msg = msg + part[::-1]

    


print(msg)
