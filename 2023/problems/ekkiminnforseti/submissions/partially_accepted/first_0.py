#!/usr/bin/python3
n, m = map(int, input().split())
candidates = [input() for _ in range(m)]
votes = [[int(candidate_id) - 1 for candidate_id in input().split()] for _ in range(n)]
print("{}".format(candidates[0]))
