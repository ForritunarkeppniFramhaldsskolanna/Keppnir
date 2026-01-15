#!/usr/bin/python3
def main():
    n = int(input())
    guest_book = []
    for _ in range(n):
        operation, name = input().split(maxsplit=1)
        if operation == "+":
            guest_book.append(name)
        elif operation == "-":
            if name in guest_book:
                guest_book.remove(name)
        elif operation == "?":
            print("Jebb" if name in guest_book else "Neibb")


if __name__ == "__main__":
    main()
