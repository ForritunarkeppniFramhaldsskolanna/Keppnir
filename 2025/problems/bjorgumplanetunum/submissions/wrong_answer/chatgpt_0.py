import sys
import math


def solve():
    T = int(sys.stdin.readline().strip())
    N = 2 * T  # We'll factor N = 2T.

    # Gather all positive divisors of N
    divisors = []
    limit = int(math.isqrt(N))
    for d in range(1, limit + 1):
        if N % d == 0:
            divisors.append(d)
            if d != N // d:
                divisors.append(N // d)
    divisors.sort()

    def check_quadratic(s, p):
        """Return how many positive-integer solutions (c,m) are given by
        x^2 - s*x + p = 0.
        Each solution must have c>0, m>0.
        Count (c,m) and (m,c) as separate if c != m."""
        D = s * s - 4 * p
        if D < 0:
            return 0
        d = int(math.isqrt(D))
        if d * d != D:
            return 0
        # We need (s ± d) even => x1,x2 integer
        if (s + d) % 2 != 0 or (s - d) % 2 != 0:
            return 0
        x1 = (s + d) // 2
        x2 = (s - d) // 2
        if x1 <= 0 or x2 <= 0:
            return 0
        if x1 == x2:
            return 1
        else:
            return 2

    count = 0
    for d in divisors:
        # Case A: s = d (even sum => 2T = s*p => p=N/s)
        # Must have s>=2 and s even
        if d >= 2 and (d % 2 == 0):
            p = N // d  # integer because d divides N
            count += check_quadratic(d, p)

        # Case B: s = d - 1 (odd sum => 2T = (s+1)*p => s+1 = d => p=N/d)
        # Must have d>=2 and d even => s = d-1 >= 2 => so d>=3
        if d >= 3 and (d % 2 == 0):
            s_odd = d - 1
            if s_odd >= 2:
                p = N // d
                count += check_quadratic(s_odd, p)

    print(count)


solve()
