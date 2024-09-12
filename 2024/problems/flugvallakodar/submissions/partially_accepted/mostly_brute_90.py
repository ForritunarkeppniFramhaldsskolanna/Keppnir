#!/usr/bin/env python3

taken = set()

n = int(input())

for _ in range(n):
    done = False
    airport = input().strip().upper()
    i_done = set()
    for i in range(len(airport)):
        if airport[i] in i_done:
            continue
        i_done.add(airport[i])
        j_done = set()
        for j in range(i + 1, len(airport)):
            if airport[j] in j_done:
                continue
            j_done.add(airport[j])
            for k in range(j + 1, len(airport)):
                code = (airport[i], airport[j], airport[k])
                if code in taken:
                    continue
                print("".join(code))
                taken.add(code)
                done = True
                break
            if done:
                break
        if done:
            break
    if not done:
        print(":(")

