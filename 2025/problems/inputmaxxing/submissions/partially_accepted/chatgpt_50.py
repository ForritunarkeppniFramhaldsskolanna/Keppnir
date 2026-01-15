def solve():
    import sys

    input = sys.stdin.readline
    n = int(input().strip())
    current_max = None
    for _ in range(n):
        x = int(input().strip())
        if current_max is None or x > current_max:
            current_max = x
    print(current_max)


if __name__ == "__main__":
    solve()
