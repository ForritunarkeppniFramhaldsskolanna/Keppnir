#!/usr/bin/python3
def solve_linear_system_mod(A, measurements, mod):
    n = len(A)

    # Forward elimination
    for i in range(n):
        # Find pivot
        for j in range(i + 1, n):
            if A[j][i] != 0:
                A[i], A[j] = A[j], A[i]  # Swap rows
                measurements[i], measurements[j] = measurements[j], measurements[i]
                break

        # Eliminate variables below pivot
        for j in range(i + 1, n):
            factor = A[j][i] * pow(A[i][i], -1, mod)  # Modular inverse
            for k in range(i, n):
                A[j][k] = (A[j][k] - factor * A[i][k]) % mod
            measurements[j] = (measurements[j] - factor * measurements[i]) % mod

    # Back substitution
    base_powers = [0] * n
    for i in range(n - 1, -1, -1):
        base_powers[i] = (
            measurements[i] - sum(A[i][j] * base_powers[j] for j in range(i + 1, n))
        ) % mod
        base_powers[i] = pow(A[i][i], -1, mod) * base_powers[i] % mod

    return base_powers


def solve_for_base_powers(K, q):
    # Matrix to store coefficients of base powers
    n = q
    A = []
    for i in range(n):
        row = [(j + 1) % (10**K) for j in range(n)]
        A.append(row)

    # Triangular pattern for setting percentages
    for i in range(n):
        for j in range(n):
            A[i, j] = (j + 1) % (10**K)

    # Collect q measurements
    measurements = []
    for _ in range(q):
        print(*A[i], flush=True)  # Send percentages to the judge
        measurement = int(input())
        measurements.append(measurement)

    # Solve for base powers (using modular linear algebra techniques)
    # ... implementation for modular Gaussian Elimination ...

    base_powers = solve_linear_system_mod(A, measurements, 10**K)

    print(*base_powers, flush=True)


# Example usage
if __name__ == "__main__":
    K, q = map(int, input().split())
    solve_for_base_powers(K, q)
