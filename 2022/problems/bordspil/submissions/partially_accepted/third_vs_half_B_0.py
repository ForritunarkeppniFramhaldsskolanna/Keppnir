#!/usr/bin/python3
n, m = map(int, input().split())
if (n+B-1)//B//3 > (m+B-1)//B//2:
    print("Arnar")
else:
    print("Unnar")
