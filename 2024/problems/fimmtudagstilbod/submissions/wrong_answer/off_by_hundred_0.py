#!/usr/bin/env python3
if __name__ == "__main__":
    y = int(input())
    cost = 1000

    for i in range(2020, y+1):
        cost += 100

    print(cost)
