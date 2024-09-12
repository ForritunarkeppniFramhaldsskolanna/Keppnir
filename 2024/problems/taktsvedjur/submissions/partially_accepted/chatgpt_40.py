#!/usr/bin/python3
def calculate_score(n, scores):
    multiplier = 1
    total_score = 0
    consecutive_hits = 0

    for score in scores:
        if score > 0:  # If the note is hit
            consecutive_hits += 1
            # Check if multiplier needs to be increased
            if consecutive_hits == 2**multiplier and multiplier < 8:
                multiplier += 1
            total_score += score * multiplier
        else:  # If the note is missed
            consecutive_hits = 0
            if multiplier > 1:
                multiplier -= 1
    return total_score

# Input reading (Example usage, replace with actual input mechanism if needed)
n = int(input())
scores = []
for _ in range(n):
    scores.append(int(input()))

# Calculate and print the total score
total_score = calculate_score(n, scores)
print(total_score)

