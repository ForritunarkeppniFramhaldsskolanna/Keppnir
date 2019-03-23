#!/usr/bin/env python3

n, k = [int(i) for i in input().split()]

bags = [int(i) for i in input().split()]

if bags.index(k) == 0:
    print("fyrst")
elif bags.index(k) == 1:
    print("naestfyrst")
else:
    print("%s fyrst" % (bags.index(k)+1))
