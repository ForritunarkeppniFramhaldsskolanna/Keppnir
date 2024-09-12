#!/usr/bin/python3
import sys
import random


random.seed(int(sys.argv[-1]) + 1)

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
min_m = int(sys.argv[3])
max_m = int(sys.argv[4])
special_case = sys.argv[5]

n = random.randint(min_n, max_n)
m = random.randint(min_m, max_m)

def generate_box(force_size=False, size=m):
    box_size = 0
    if force_size:
        box_size = size
    else:
        box_size = random.randint(0, size)
    
    return random.sample(range(1, m + 1), box_size)

sys.stdout.write(f"{n} {m}\n")

boxes = []
if special_case == "one_empty_box":
    boxes.append(generate_box(force_size=True, size=0))
    # n - 1 as we already appended one box
    for i in range(n-1):
        boxes.extend(generate_box())

elif special_case == "ordered":
    box = [1]
    for i in range(n):
        box_size = random.randint(0, m-1)
        box.extend(sorted(random.sample(range(2, m + 1), box_size)))
    assert box[0] == 1, f"1 is not the first element in box: {box}"
    assert len(box) <= m, f"Too many elements in box: {box}"
    assert len(box) != 0, f"Box is empty: {box}"
    assert box == sorted(box), f"Box is not sorted: {box}"
    boxes.append(box)
elif special_case == "last_piece_missing_in_all_boxes":
    box = range(1, m)
    for i in range(n):
        boxes.append(list(box))
elif special_case == "first_piece_missing_in_all_boxes":
    box = range(2, m+1)
    for i in range(n):
        boxes.append(list(box))
elif special_case == "break_wrong_io":
    boxes = [list(range(1, m - 1)) + [m]]


# General case
else:
    for i in range(n):
        box = generate_box()
        boxes.append(box)

random.shuffle(boxes)

# print the boxes
for i, box in enumerate(boxes):
    print(f"{len(box)} {' '.join(map(str, box))}".strip())
