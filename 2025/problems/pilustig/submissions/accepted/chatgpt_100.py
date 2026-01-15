def main():
    import sys

    data = sys.stdin.read().strip().split()
    if not data:
        return
    x = int(data[0])

    # Define the available moves: each move is a tuple (name, score)
    moves = []
    moves.append(("Bullseye", 50))
    moves.append(("Outer bullseye", 25))
    for i in range(1, 21):
        moves.append((f"Single {i}", i))
        moves.append((f"Double {i}", 2 * i))
        moves.append((f"Triple {i}", 3 * i))

    solutions = []

    # One dart solution
    for m in moves:
        if m[1] == x:
            solutions.append([m[0]])

    # Two dart solutions
    for m1 in moves:
        for m2 in moves:
            if m1[1] + m2[1] == x:
                solutions.append([m1[0], m2[0]])

    # Three dart solutions
    for m1 in moves:
        for m2 in moves:
            for m3 in moves:
                if m1[1] + m2[1] + m3[1] == x:
                    solutions.append([m1[0], m2[0], m3[0]])

    # Print the output
    # First line: number of ways
    sys.stdout.write(f"{len(solutions)}\n")
    for sol in solutions:
        sys.stdout.write(f"{len(sol)}\n")
        for move_name in sol:
            sys.stdout.write(f"{move_name}\n")


if __name__ == "__main__":
    main()
