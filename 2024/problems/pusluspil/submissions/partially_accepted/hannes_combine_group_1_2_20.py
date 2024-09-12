#!/usr/bin/env python3

n, m = map(int, input().split())

expected_number = 1

if m == 0:
    print("Jebb")
else:
    pieces = map(int, input().split())
    for piece in list(pieces)[1:]:
        if expected_number != piece:
            print("Neibb")
            exit()
        else:
            expected_number += 1
        
    if expected_number == m+1:
        print("Jebb")
    else:
        print("Neibb")
