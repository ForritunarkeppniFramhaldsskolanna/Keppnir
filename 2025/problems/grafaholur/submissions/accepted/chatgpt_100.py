def solve():
    import sys

    data = [line.strip() for line in sys.stdin]
    # Parse inputs
    n = int(data[0])
    h = int(data[1])
    c = int(data[2])
    m = int(data[3])
    # y might be integer or decimal, so parse as float
    y = float(data[4])

    # Compute the required time
    # Formula: T = (y * n * h) / (m * c)
    T = (y * n * h) / (m * c)

    # Print with reasonable formatting
    print(f"{T:.10f}")


solve()
