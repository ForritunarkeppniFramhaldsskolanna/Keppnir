#!/usr/bin/python3
def find_real_gold_stack(n):
    start = 0
    end = n - 1
    while start <= end:
        mid = (start + end) // 2
        # Prepare the query for the left half
        query = ['0'] * n  # Initialize all with '0'
        for i in range(start, mid + 1):
            query[i] = str(i - start + 1)  # Incrementally add coins from the left half
        print(f"? {' '.join(query)}")
        total_weight = int(input())
        # Calculate expected weight if all coins in the query are counterfeit
        expected_weight = sum(range(1, mid - start + 2)) * n + (mid - start + 1)
        if total_weight > expected_weight:
            # The real gold is in the left half
            end = mid
        else:
            # The real gold is in the right half
            start = mid + 1
    # Found the stack with real gold
    print(f"! {start + 1}")

if __name__ == "__main__":
    n = int(input())
    find_real_gold_stack(n)

