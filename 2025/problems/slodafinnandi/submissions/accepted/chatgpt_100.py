def solve():
    import sys

    data = sys.stdin.read().strip().split()
    if not data:
        return
    n = int(data[0])
    # Work in units (each unit = 5 feet)
    T = n // 5

    # S1: Sum coming from one “piece” of the counting (see explanation above).
    A = (2 * T + 1) // 3  # floor((2T+1)/3)
    S1 = (A + 1) * (A + 2) // 2 + (T - A) * (T - A + 1)

    # S2: Sum the contributions splitting x into even and odd.
    # For even x = 2k, floor(2k/2) = k and term becomes T - 3k.
    E = T // 3
    S2_even = (E + 1) * T - 3 * (E * (E + 1) // 2)

    # For odd x = 2k+1, floor((2k+1)/2) = k and term is T - 3k - 1.
    if T - 1 < 0:
        S2_odd = 0
    else:
        O = (T - 1) // 3
        S2_odd = (O + 1) * (T - 1) - 3 * (O * (O + 1) // 2)

    S2 = S2_even + S2_odd
    S = S1 + S2

    # Full grid: by symmetry, the final count is:
    ans = 4 * S - 4 * T - 3

    sys.stdout.write(str(ans))


if __name__ == "__main__":
    solve()
