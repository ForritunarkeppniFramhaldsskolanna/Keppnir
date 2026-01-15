def solve():
    import sys

    data = sys.stdin.read().strip().split()
    if not data:
        return
    i = int(data[0])
    # Set default values based on input count
    if i == 1:
        l = int(data[1])
        w = l
        h = 3
    elif i == 2:
        w = int(data[1])
        l = int(data[2])
        h = 3
    elif i == 3:
        w = int(data[1])
        l = int(data[2])
        h = int(data[3])
    else:
        # Just in case, though by problem statement i is 1, 2, or 3.
        return

    wall_blocks = (2 * w + 2 * l - 4) * (h - 1)
    roof_blocks = w * l
    total_blocks = wall_blocks + roof_blocks
    print(total_blocks)


if __name__ == "__main__":
    solve()
