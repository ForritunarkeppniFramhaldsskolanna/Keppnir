def solve():
    import sys

    data = sys.stdin.read().strip().split()
    # First line: k (number of carriers = Dagur + friends)
    k = int(data[0])
    # Second line: n (number of items)
    n = int(data[1])

    # Read the n items
    items = []
    idx = 2
    for _ in range(n):
        name = data[idx]
        weight = int(data[idx + 1])
        items.append((name, weight))
        idx += 2

    # 1) Sort items by descending weight; if tie, by name ascending
    items.sort(key=lambda x: (-x[1], x[0]))

    # 2) Each of the k-1 friends takes floor(n/k) items from the front
    friend_quota = n // k
    num_friend_items = friend_quota * (k - 1)

    # 3) Dagur gets the leftover items
    dagur_items = items[num_friend_items:]  # slice from that index to end

    # 4) Sort Dagur's items by ascending weight (and name on tie)
    dagur_items.sort(key=lambda x: (x[1], x[0]))

    # 5) Output: sum of Dagur's weights, then the names line by line
    total_weight = sum(item[1] for item in dagur_items)
    print(total_weight)
    for name, _ in dagur_items:
        print(name)


solve()
