def solve():
    a = int(input().strip())
    b = int(input().strip())

    diff = abs(a - b)
    # If the direct difference is more than 180, the shorter path is on the other side of the circle
    if diff > 180:
        diff = 360 - diff

    print(diff)


# If you want to test with sample inputs, uncomment and run these lines locally:
# Sample Input 1:
# print(run_io_fun('170\n100\n', solve))
# Expected Output: 70

# Sample Input 2:
# print(run_io_fun('355\n7\n', solve))
# Expected Output: 12
solve()
