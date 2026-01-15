def solve():
    import sys

    # Read inputs
    n = int(sys.stdin.readline().strip())
    m = int(sys.stdin.readline().strip())

    # Compute x = number of sheep
    diff = m - 2 * n

    # Check divisibility by 2
    if diff % 2 == 0:
        x = diff // 2
        # Check if x is in the valid range
        if 0 <= x <= n:
            print(x)
            return

    # If no valid solution found
    print("Rong talning")


solve()
