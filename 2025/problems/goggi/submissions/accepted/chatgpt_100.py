def solve():
    # Read the input, which should be something like "13 ? 5"
    tokens = input().split()

    # The first token is n, the second token is "?", the third token is m
    n = int(tokens[0])
    m = int(tokens[2])

    # Compare n and m
    if n > m:
        print(">")
    elif n < m:
        print("<")
    else:
        print("Goggi svangur!")


solve()
