#!/usr/bin/env python3
import sys


def main():
    # Read the number of batteries
    line = sys.stdin.readline().strip()
    if not line:
        sys.exit(0)
    n = int(line)

    pairs = []  # Will hold tuples (i, j) where one is good.

    # First round: test adjacent pairs (1,2), (3,4), ..., (n-1, n)
    for i in range(1, n + 1, 2):
        print(i, i + 1, flush=True)
        result = sys.stdin.readline().strip()
        if result == "Ljos!":
            # Found a working pair; exit immediately.
            sys.exit(0)
        else:
            # This pair is ambiguous: one battery is good, the other dead.
            pairs.append((i, i + 1))

    # At this point, every tested pair failed, so each contains exactly one good battery.
    # We don't know which one in each pair is good.
    candidate = pairs[0][0]
    candidate_alternate = pairs[0][1]
    good_list = []  # Will record a battery deduced to be good from each subsequent pair.

    # Test the candidate battery with the first battery from every other pair.
    for x, y in pairs[1:]:
        print(candidate, x, flush=True)
        result = sys.stdin.readline().strip()
        if result == "Ljos!":
            # Candidate and battery x are both good.
            sys.exit(0)
        else:
            # Since (x,y) has one good battery and x failed with candidate,
            # battery x is dead so battery y must be good.
            good_list.append(y)

    # Now test candidate with one battery from the known good_list.
    print(candidate, good_list[0], flush=True)
    result = sys.stdin.readline().strip()
    if result == "Ljos!":
        sys.exit(0)
    else:
        # Candidate must have been dead; so the alternate from the first pair is good.
        candidate = candidate_alternate
        print(candidate, good_list[0], flush=True)
        # This test must light up.
        sys.stdin.readline().strip()
        sys.exit(0)


if __name__ == "__main__":
    main()
