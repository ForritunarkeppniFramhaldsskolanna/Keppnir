#!/usr/bin/python3

from math import factorial



def mod_factorial(n, mod=1_000_000_007):

    """Calculate n! % mod."""

    result = 1

    for i in range(1, n + 1):

        result = (result * i) % mod

    return result



def mod_inverse(x, mod=1_000_000_007):

    """Calculate modular inverse of x under modulo mod."""

    # Fermat's Little Theorem for mod prime

    return pow(x, mod - 2, mod)



def calculate_drafts(n):

    mod = 1_000_000_007

    # Total steps for bans and picks

    bans = 6 + 3  # First 6 bans, then 3 more after some picks

    picks_in_same_step = factorial(2) ** 2  # Two steps where 2 champions are picked by the same team

    picks = 10  # Total picks



    # Calculate bans permutations

    bans_perms = mod_factorial(n, mod) // mod_factorial(n - bans, mod)

    bans_perms %= mod



    # Calculate picks permutations, considering the interchangeable picks within the same step

    picks_perms = mod_factorial(n - bans, mod) // (mod_factorial(n - bans - picks, mod) * picks_in_same_step)

    picks_perms %= mod



    # Total draft processes is the product of bans_perms and picks_perms

    total_drafts = (bans_perms * picks_perms) % mod

    return total_drafts



# Calculate for given n values

print(calculate_drafts(int(input())))
