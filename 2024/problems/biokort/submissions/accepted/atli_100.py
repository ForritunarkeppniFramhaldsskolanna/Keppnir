#!/usr/bin/python3
import sys

n, m, k = map(int, sys.stdin.readline().strip().split())
pop = sorted([int(sys.stdin.readline().strip().split()[1]) for _ in range(n)])

cards = 0
cur_cost = sum(pop) * m
bst_sum, bst_card = cur_cost, 0

for i in range(len(pop)):
    while cards < pop[i]:
        cur_cost += k
        cur_cost -= (len(pop) - i) * m
        cards += 1
        if bst_sum > cur_cost:
            bst_sum = cur_cost
            bst_card = cards

print(bst_card, bst_sum)
