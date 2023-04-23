#!/usr/bin/python3
p, w = map(int, input().split())

# Calculate the number of '#' symbols to include in the progress bar
num_hashes = int(p / 100 * w)

# Create the progress bar string
progress_bar = '[' + '#' * num_hashes + '-' * (w - num_hashes) + ']'

# Print the progress bar with the percentage
print(progress_bar, '|', '{:>3}%'.format(p))
