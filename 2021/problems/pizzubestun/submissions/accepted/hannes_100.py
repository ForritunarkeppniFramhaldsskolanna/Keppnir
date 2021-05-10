#!/usr/bin/env python3

n = int(input())

pizzas = []
for i in range(n):
    name, price = input().split()
    pizzas.append((int(price), name))

pizzas = sorted(pizzas)

total = 0


while len(pizzas) >= 2:
    pizza = pizzas.pop()
    total += pizza[0]
    pizzas.pop()

if len(pizzas) == 1:
    pizza = pizzas.pop()
    total += pizza[0]

print(total)