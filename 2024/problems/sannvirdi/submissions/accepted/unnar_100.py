#!/usr/bin/python3
n = int(input())

contestants = []
for i in range(n):
    name, guess = input().split()
    contestants.append((int(guess), name))

q = int(input())
guesses = []
for i in range(q):
    guesses.append((int(input()),i))

contestants = sorted(contestants)
guesses = sorted(guesses)
ans = []

i = 0
name = ":("
for guess, j in guesses:
    while i < n and contestants[i][0] <= guess:
        name = contestants[i][1]
        i += 1
    ans.append((j, name))

for _, name in sorted(ans):
    print(name)
