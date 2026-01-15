points = (
    [
        (50, "Bullseye"),
        (25, "Outer bullseye"),
    ]
    + [(3 * i, f"Triple {i}") for i in range(1, 21)][::-1]
    + [(2 * i, f"Double {i}") for i in range(1, 21)][::-1]
    + [(i, f"Single {i}") for i in range(1, 21)][::-1]
)[::-1]

x = int(input())

answers = []

for point_1, name_1 in points:
    if point_1 == x:
        answers.append([name_1])

for point_1, name_1 in points:
    for point_2, name_2 in points:
        if point_1 + point_2 == x:
            answers.append([name_1, name_2])

for point_1, name_1 in points:
    for point_2, name_2 in points:
        for point_3, name_3 in points:
            if point_1 + point_2 + point_3 == x:
                answers.append([name_1, name_2, name_3])

print(len(answers))
for ans in answers:
    print(len(ans))
    print("\n".join(ans))
