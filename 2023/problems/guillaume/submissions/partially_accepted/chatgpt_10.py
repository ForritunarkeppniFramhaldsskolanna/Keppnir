#!/usr/bin/python3
n = int(input())  # fjöldi leikja
results = input()  # niðurstöður leikja

# Teljum fjölda sigra Guillaume og Arnars
g_wins = 0
a_wins = 0
for i in range(n):
    if results[i] == 'G':
        g_wins += 1
    elif results[i] == 'A':
        a_wins += 1

# Skrifum út niðurstöðurnar
print("{}-{}".format(g_wins, a_wins))
