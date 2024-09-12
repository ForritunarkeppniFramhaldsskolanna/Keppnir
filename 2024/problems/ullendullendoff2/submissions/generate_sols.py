#!/usr/bin/python3
import random

random.seed(1337)

min_n = 1
max_n = 20

def find_perm_for_n(n):
    arr = list(range(0, n))
    random.shuffle(arr)
    while arr[12%n] != 0:
        random.shuffle(arr)
    return arr

lines = []
lines.append("#!/usr/bin/python3")
lines.append("n = int(input())")
lines.append("names = [input() for _ in range(n)]")
for i in range(min_n, max_n+1):
    directory = "accepted" if i == max_n else "partially_accepted"
    with open(f"{directory}/{i:02}_groups_{5*i}.py", "w") as f:
        if_string = f"if n == {i}:" if i == min_n else f"elif n == {i}:"
        lines.append(f"{if_string}")
        perm = find_perm_for_n(i)
        for j in perm:
            lines.append(f"    print(names[{j}])")
        f.write('\n'.join(lines))
        f.write('\n')

