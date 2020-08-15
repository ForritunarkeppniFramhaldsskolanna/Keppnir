#!/usr/env/bin python3
y = int(input())
if y % 4 == 0 and (y % 100 != 0 or y % 400 == 0):
    y1 = y // 4 -  y // 100 + y // 400
    y2 = 2020 // 4 - 2020 // 100 + 2020 // 400
    print(y1 - y2)
else:
    print("Neibb")
