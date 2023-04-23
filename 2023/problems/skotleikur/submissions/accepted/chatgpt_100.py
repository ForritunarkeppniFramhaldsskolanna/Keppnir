#!/usr/bin/python3

def count_combinations(K, a, b):
    count = 0
    combinations = []
    for x in range(K//a + 1):
        y = (K - a*x) // b
        if a*x + b*y == K:
            count += 1
            combinations.append((x, y))
    return count, combinations

# Had to tell chatgpt explicitly that input was read on three lines, not one
K = int(input().strip())
a = int(input().strip())
b = int(input().strip())

result = count_combinations(K, a, b)
print(result[0])
for x, y in result[1]:
    print(x, y)

