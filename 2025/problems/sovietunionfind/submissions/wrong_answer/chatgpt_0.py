def solve():
    import sys

    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    q = int(next(it))

    # For 1-indexing:
    ruler = list(range(n + 1))  # ruler[i] is the current ruler (leader) of area i.
    # For each leader, store the list of areas in its union.
    group = [None] * (n + 1)
    for i in range(1, n + 1):
        group[i] = [i]

    output = []

    for _ in range(q):
        op = next(it)
        if op == "a":
            x = int(next(it))
            y = int(next(it))
            rx = ruler[x]
            ry = ruler[y]
            if rx == ry:
                continue
            # The union must take the leader from x (i.e. rx).
            # All areas in the union of ry now become ruled by rx.
            for area in group[ry]:
                ruler[area] = rx
            group[rx].extend(group[ry])
            group[ry] = []  # The old group is now empty.
        elif op == "b":
            x = int(next(it))
            r = ruler[x]
            # Balkanisation: every area in group[r] becomes independent.
            for area in group[r]:
                ruler[area] = area
                group[area] = [area]
            group[r] = []  # Clear the union.
        elif op == "c":
            x = int(next(it))
            output.append(str(ruler[x]))

    sys.stdout.write("\n".join(output))


if __name__ == "__main__":
    solve()
