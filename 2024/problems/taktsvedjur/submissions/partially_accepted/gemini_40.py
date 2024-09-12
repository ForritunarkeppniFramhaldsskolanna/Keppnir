#!/usr/bin/python3
def calculate_score(notes):
    total_score = 0
    multiplier = 1

    for note_value in notes:
        if note_value > 0:  # Note was hit
            total_score += note_value * multiplier
            multiplier = min(multiplier * 2, 8)  # Increase multiplier, up to 8
        else:  # Note was missed
            multiplier = max(multiplier // 2, 1)  # Decrease multiplier, down to 1

    return total_score


# Get input
num_notes = int(input())
notes = []
for _ in range(num_notes):
    notes.append(int(input()))

# Calculate and print the score
score = calculate_score(notes)
print(score)
