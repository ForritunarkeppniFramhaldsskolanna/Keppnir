#!/usr/bin/env python3
if __name__ == "__main__":
    y = int(input())
    cost = 1000

    if y > 2020:
        cost += (y - 2020) * 100

    print(cost)
