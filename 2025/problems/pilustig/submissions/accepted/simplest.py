#!/usr/bin/python3

throws = [
    (1, "Single 1"),
    (2, "Single 2"),
    (3, "Single 3"),
    (4, "Single 4"),
    (5, "Single 5"),
    (6, "Single 6"),
    (7, "Single 7"),
    (8, "Single 8"),
    (9, "Single 9"),
    (10, "Single 10"),
    (11, "Single 11"),
    (12, "Single 12"),
    (13, "Single 13"),
    (14, "Single 14"),
    (15, "Single 15"),
    (16, "Single 16"),
    (17, "Single 17"),
    (18, "Single 18"),
    (19, "Single 19"),
    (20, "Single 20"),
    (2, "Double 1"),
    (4, "Double 2"),
    (6, "Double 3"),
    (8, "Double 4"),
    (10, "Double 5"),
    (12, "Double 6"),
    (14, "Double 7"),
    (16, "Double 8"),
    (18, "Double 9"),
    (20, "Double 10"),
    (22, "Double 11"),
    (24, "Double 12"),
    (26, "Double 13"),
    (28, "Double 14"),
    (30, "Double 15"),
    (32, "Double 16"),
    (34, "Double 17"),
    (36, "Double 18"),
    (38, "Double 19"),
    (40, "Double 20"),
    (3, "Triple 1"),
    (6, "Triple 2"),
    (9, "Triple 3"),
    (12, "Triple 4"),
    (15, "Triple 5"),
    (18, "Triple 6"),
    (21, "Triple 7"),
    (24, "Triple 8"),
    (27, "Triple 9"),
    (30, "Triple 10"),
    (33, "Triple 11"),
    (36, "Triple 12"),
    (39, "Triple 13"),
    (42, "Triple 14"),
    (45, "Triple 15"),
    (48, "Triple 16"),
    (51, "Triple 17"),
    (54, "Triple 18"),
    (57, "Triple 19"),
    (60, "Triple 20"),
    (25, "Outer bullseye"),
    (50, "Bullseye"),
]

ways = 0
target = int(input())

for x in throws:
    if x[0] == target:
        ways += 1
for x in throws:
    for y in throws:
        if x[0] + y[0] == target:
            ways += 1
for x in throws:
    for y in throws:
        for z in throws:
            if x[0] + y[0] + z[0] == target:
                ways += 1

print(ways)

for x in throws:
    if x[0] == target:
        print(1)
        print(x[1])
for x in throws:
    for y in throws:
        if x[0] + y[0] == target:
            print(2)
            print(x[1])
            print(y[1])
for x in throws:
    for y in throws:
        for z in throws:
            if x[0] + y[0] + z[0] == target:
                print(3)
                print(x[1])
                print(y[1])
                print(z[1])
