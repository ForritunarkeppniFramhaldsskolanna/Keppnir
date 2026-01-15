from math import ceil


def main() -> None:
    sum_c = 0

    n = int(input())
    if n == 1:
        a, b, c = map(int, input().split())
        print(ceil(c / ((b + 1) - (a))))
        return

    for _ in range(n):
        a, b, c = map(int, input().split())
        sum_c += c
    print(ceil(c / n))


if __name__ == "__main__":
    main()
