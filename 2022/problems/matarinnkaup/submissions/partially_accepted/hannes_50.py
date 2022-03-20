#!/usr/bin/env python3

u, k = map(int, input().split())

recipes = {}

for _ in range(u):
    recipe = input()
    recipes[recipe] = []
    h = int(input())
    for _ in range(h):
        ingredient, qty = input().split()
        qty = int(qty)
        recipes[recipe].append((ingredient, qty))

ingr_count = {}

for _ in range(k):
    n = int(input())
    for _ in range(n):
        recipe, qty = input().split()
        qty = int(qty)
        for rec_ingr, rec_ingr_qty in recipes[recipe]:
            if rec_ingr not in ingr_count:
                ingr_count[rec_ingr] = 0
            ingr_count[rec_ingr] += rec_ingr_qty * qty


for ingr in sorted(ingr_count.keys()):
    print(ingr, ingr_count[ingr])
