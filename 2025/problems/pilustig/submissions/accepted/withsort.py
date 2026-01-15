#!/usr/bin/python3

throws = [(3, "Outer bullseye", 25), (4, "Bullseye", 50)]

for i in range(1, 21):
    throws.append((0, f"Single {i}", i))
    throws.append((1, f"Double {i}", i + i))
    throws.append((2, f"Triple {i}", i + i + i))

by_len = [[], [], []]

target = int(input())

for x in throws:
    if x[2] == target:
        by_len[0].append([x])
    for y in throws:
        if x[2] + y[2] == target:
            by_len[1].append([x, y])
        for z in throws:
            if x[2] + y[2] + z[2] == target:
                by_len[2].append([x, y, z])

print(len(by_len[0]) + len(by_len[1]) + len(by_len[2]))

for i in range(3):
    for j in range(i, -1, -1):
        by_len[i].sort(key=lambda x: x[j][2])
        by_len[i].sort(key=lambda x: x[j][0])
    for j in range(len(by_len[i])):
        print(i + 1)
        for _, name, _ in by_len[i][j]:
            print(name)
