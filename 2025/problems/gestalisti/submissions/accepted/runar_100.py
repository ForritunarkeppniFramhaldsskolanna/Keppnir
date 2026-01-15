#!/usr/bin/python3
def main():
    n = int(input())
    guest_book = set()
    for _ in range(n):
        operation, name = input().split(maxsplit=1)
        if operation == "+":
            guest_book.add(name)
        elif operation == "-":
            try:
                guest_book.remove(name)
            except KeyError:
                pass
        elif operation == "?":
            print("Jebb" if name in guest_book else "Neibb")


if __name__ == "__main__":
    main()
