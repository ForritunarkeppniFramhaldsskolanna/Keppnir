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


recipe_count = {}
for _ in range(k):
    n = int(input())
    for _ in range(n):
        recipe, qty = input().split()
        qty = int(qty)
        if recipe not in recipe_count:
            recipe_count[recipe] = 0
        recipe_count[recipe] += qty

ingr_count = {}
for recipe in recipe_count:
    ingredients = recipes[recipe]
    for ingredient, ingredient_qty in ingredients:
        if ingredient not in ingr_count:
            ingr_count[ingredient] = 0
        ingr_count[ingredient] += recipe_count[recipe] * ingredient_qty

for ingr in sorted(ingr_count.keys()):
    print(ingr, ingr_count[ingr])
