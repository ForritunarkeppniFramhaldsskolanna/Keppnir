#!/usr/bin/python3
def calculate_teams(n):
    max_teams = n
    min_teams = n // 3
    if n % 3 != 0:
        min_teams += 1
    print(max_teams)
    print(min_teams)


n = int(input())
calculate_teams(n)
