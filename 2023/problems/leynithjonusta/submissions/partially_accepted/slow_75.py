#!/usr/bin/python3
line = input()
while ' ' in line:
    ind = line.index(' ')
    line = line[:ind] + line[ind+1:]
print(line)
