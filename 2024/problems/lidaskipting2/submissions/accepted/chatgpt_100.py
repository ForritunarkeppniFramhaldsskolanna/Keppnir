#!/usr/bin/python3

# Correct calculation for very large numbers using integer division and modulo to handle precision
def calculate_teams_precise(n):
    # Maximum teams remains the same
    max_teams = n
    # Adjusted minimum teams calculation for large numbers
    # Calculate remainder to see if there are extra teams with less than 3 members
    remainder = n % 3
    # Calculate minimum teams with precise division
    min_teams = n // 3 + (1 if remainder > 0 else 0)
    return max_teams, min_teams

# Precise calculation for the very large number
max_teams_precise, min_teams_precise = calculate_teams_precise(int(input()))
print(max_teams_precise)
print(min_teams_precise)
