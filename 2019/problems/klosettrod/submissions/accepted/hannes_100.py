#!/usr/bin/env python3
input()
nums = [int(i) for i in input().split()]
snums = sorted(nums)
print(" ".join([str(nums.index(i) + 1) for i in snums][::-1]))