#!/usr/bin/python3
Y = int(input())

def leap(i):
    return (i % 4 == 0 and i % 100 != 0) or i % 400 == 0

cnt = 0
for i in range(2021, Y+1):
    if leap(i):
        cnt += 1

if leap(Y):
    print(cnt)
else:
    print("Neibb")
