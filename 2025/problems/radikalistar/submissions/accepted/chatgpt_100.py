def solve():
    import sys

    data = sys.stdin.read().split()
    if not data:
        return
    pos = 0
    n = int(data[pos])
    pos += 1
    q = int(data[pos])
    pos += 1

    # Initially, all members [1...n] are in group 0.
    member_to_group = [0] * (n + 1)
    groups = {0: set(range(1, n + 1))}
    next_group_id = 1

    out_lines = []
    for _ in range(q):
        typ = data[pos]
        pos += 1
        if typ == "r":
            # Radicalist query: the next integer is t, followed by t members.
            t = int(data[pos])
            pos += 1
            # We'll group the radicalists by the group they are leaving.
            group_to_radicals = {}
            for i in range(t):
                x = int(data[pos])
                pos += 1
                g = member_to_group[x]
                if g not in group_to_radicals:
                    group_to_radicals[g] = set()
                group_to_radicals[g].add(x)
            # Process each group that is splitting.
            for g, rad_set in group_to_radicals.items():
                # Remove the radicalists from their original group.
                group = groups[g]
                for x in rad_set:
                    group.remove(x)
                if not group:  # if the original group becomes empty, remove it
                    del groups[g]
                # Create a new group for the radicalists
                new_id = next_group_id
                next_group_id += 1
                groups[new_id] = rad_set
                for x in rad_set:
                    member_to_group[x] = new_id

        elif typ == "s":
            # Output the number of groups (empty groups are not counted)
            out_lines.append(str(len(groups)))
        elif typ == "m":
            # Output all members in the same group as u.
            u = int(data[pos])
            pos += 1
            g = member_to_group[u]
            group_members = groups[g]
            out_lines.append(" ".join(map(str, group_members)))
    sys.stdout.write("\n".join(out_lines))


solve()
