#!/usr/bin/env python3
s1 = input().strip()
s2 = input().strip()
# If s2 == 0 we can always round or truncate by choosing a large enough power of 10
if s2 == "0.0":
    print("Veit ekki")
    exit(0)
# If s2 has more digits before the decimal, it must be larger
# Truncation can never make the value larger, so we must be rounding
if len(s1.split('.')[0]) < len(s2.split('.')[0]):
    print("Runnun")
    exit(0)
assert len(s1.split('.')[0]) == len(s2.split('.')[0])
a = [c for c in s1 if c != '.']
b = [c for c in s2 if c != '.']
# Now a and b must be aligned
for i in range(len(b)):
    # Loop condition, a and b are equal up to this point
    # Seen to be true as any disagreement breaks out of the loop
    if b[i] > a[i]:
        # If a and b agree up to here but b is greater at this point,
        # the value b represents is larger and we must be rounding
        print("Runnun")
        exit(0)
    if b[i] < a[i]:
        # No truncation or rounding can make the first digit of b smaller than
        # in a (unless we go to zero), so here we must have i > 0.
        # We have either rounded down or truncated, affecting the i-th digit
        # If the (i-1)-th digit is zero, we could be using a larger power of 10
        # In this case we could be rounding or truncating to that power of 10
        # If it is nonzero we must be doing it at exactly this power of 10
        # Then if our digit is 4 or below it would be valid rounding, otherwise not
        if a[i] >= '5' and a[i - 1] != '0':
            print("Styfun")
        else:
            print("Veit ekki")
        exit(0)
# If we have not exited yet then b is a prefix of a
# This means we can always achieve b through truncation
# a must be longer than b by input specification
# Now by the same argument as in the loop, we check for rounding in the same way
if a[len(b)] >= '5' and a[len(b) - 1] != '0':
    print("Styfun")
else:
    print("Veit ekki")
