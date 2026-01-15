def solve():
    import sys

    input = sys.stdin.readline  # for faster reads

    N = int(input().strip())
    guest_set = set()
    answers = []

    for _ in range(N):
        line = input().rstrip("\n")
        # Example line: "+ alex" or "? eva" or "- hera"
        cmd, name = line.split(maxsplit=1)

        if cmd == "+":
            # Add name to the set (duplicate adds are safe)
            guest_set.add(name)
        elif cmd == "-":
            # Remove name if it exists (the problem might guarantee it does)
            guest_set.discard(name)  # discard won't error if not present
        elif cmd == "?":
            # Check presence
            if name in guest_set:
                answers.append("Jebb")
            else:
                answers.append("Neibb")
        else:
            # In case there's an unexpected command
            raise ValueError(f"Unknown command: {cmd}")

    print("\n".join(answers))


solve()
