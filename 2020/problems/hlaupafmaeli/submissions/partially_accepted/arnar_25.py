#!/usr/bin/python3
Y = int(input())

if Y % 4 == 0 and Y not in [2100, 2200, 2300]:
    ans = (Y - 2020) // 4
    if Y > 2100:
        ans -= 1
    if Y > 2200:
        ans -= 1
    if Y > 2300:
        ans -= 1
    print(ans)
else:
    print("Neibb")
