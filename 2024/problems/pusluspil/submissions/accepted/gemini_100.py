#!/usr/bin/python3
def can_complete_puzzle(n, m, boxes):
    seen_pieces = set()
    for box in boxes:
        num_pieces = box[0]
        for piece in box[1:]:  # Iterate through puzzle pieces in the box
            seen_pieces.add(piece)

    return "Jebb" if len(seen_pieces) == m else "Neibb"


# Get Input
n, m = map(int, input().split())
boxes = []
for _ in range(n):
    boxes.append(list(map(int, input().split())))

# Solve
result = can_complete_puzzle(n, m, boxes)
print(result)
