def main():
    import sys

    input = sys.stdin.readline

    # Read input
    n, T = map(int, input().split())
    words = list(map(int, input().split()))

    # Sort problems by word count (increasing order)
    words.sort()

    # Precompute prefix sums
    prefix = [0] * n
    prefix[0] = words[0]
    for i in range(1, n):
        prefix[i] = prefix[i - 1] + words[i]

    # f(S): total penalty if typing at speed S (words per minute)
    def penalty(S):
        tot = 0
        for p in prefix:
            tot += p // S
            # early exit if penalty already too high
            if tot >= T:
                break
        return tot

    # Binary search for minimal S with penalty(S) < T.
    lo, hi = 1, prefix[-1] + 1
    while lo < hi:
        mid = (lo + hi) // 2
        if penalty(mid) < T:
            hi = mid
        else:
            lo = mid + 1

    print(lo)


if __name__ == "__main__":
    main()
