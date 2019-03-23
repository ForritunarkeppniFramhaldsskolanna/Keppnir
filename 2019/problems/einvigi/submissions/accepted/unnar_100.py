#!/usr/bin/python3
import sys
n,m,k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

awin = 0
bwin = 0
for i in range(n):
    if a[i] > b[i]:
        awin += 1
    elif b[i] > a[i]:
        bwin += 1

for i in range(m):
    if a[i] > b[i]: awin -= 1
    if a[i] < b[i]: bwin -= 1
    a[i] += k
    if a[i] > b[i]: awin += 1
    if a[i] < b[i]: bwin += 1

    '''if a[i] < b[i] and a[i] + k > b[i]:
        awin += 1
        bwin -= 1
    elif a[i] < b[i] and a[i] + k == b[i]:
        bwin -= 1
    elif a[i] == b[i]:
        awin += 1'''
if awin > bwin:
    print(0)
    sys.exit(0)

i, j = 0, m
while j < n:
    if a[i] > b[i]: awin -= 1
    if a[i] < b[i]: bwin -= 1
    a[i] -= k
    if a[i] > b[i]: awin += 1
    if a[i] < b[i]: bwin += 1

    if a[j] > b[j]: awin -= 1
    if a[j] < b[j]: bwin -= 1
    a[j] += k
    if a[j] > b[j]: awin += 1
    if a[j] < b[j]: bwin += 1


    '''if a[i] < b[i] and a[i] + k > b[i]:
        awin -= 1
        bwin += 1
    elif a[i] < b[i] and a[i] + k == b[i]:
        bwin += 1
    elif a[i] == b[i]:
        awin -= 1
    if a[j] < b[j] and a[j] + k > b[j]:
        awin += 1
        bwin -= 1
    elif a[j] < b[j] and a[j] + k == b[j]:
        bwin -= 1
    elif a[j] == b[j]:
        awin += 1'''
    i, j = i+1, j+1
    if awin > bwin:
        print(i)
        sys.exit(0)
print("Neibb")
