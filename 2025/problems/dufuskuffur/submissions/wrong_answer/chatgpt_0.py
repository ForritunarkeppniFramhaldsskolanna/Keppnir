def solve():
    n = int(input().strip())  # number of doves
    b = int(input().strip())  # number of boxes

    # If there are more doves than boxes, at least one box would hold 2 or more doves,
    # violating the "at most 1 dove per box" requirement.
    if n <= b:
        print("Dufur passa")
    else:
        print("Dufur passa ekki")


solve()
