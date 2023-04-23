#!/usr/bin/python3
n = int(input())  # number of pizza slices
m = int(input())  # number of residents in the household

# Calculate the number of slices each resident can have, rounding down
slices_per_resident = n // m

# Calculate the number of slices left over
slices_left_over = n - (slices_per_resident * m)

print(slices_left_over)
