#!/usr/bin/python3
import math

def query(indices):
    # Send query to the arcade machine and return the result
    query_str = "? " + " ".join(str(i) for i in indices)
    print(query_str, flush=True)
    response = input()
    return list(map(int, response.strip().split()))

n = int(input())

# Initialize empty buckets
buckets = [[] for _ in range(math.ceil(math.sqrt(n)))]

# Query the first element of each bucket
for i in range(len(buckets)):
    indices = [i * len(buckets) + 1]
    response = query(indices)
    buckets[i].append(response[0])

# Sort the first bucket
buckets[0].sort()

# Find the smallest element in the first bucket
smallest = buckets[0][0]

# Repeatedly query the first element of remaining buckets
# that have at least one element smaller than smallest
for i in range(1, len(buckets)):
    if not any(x < smallest for x in buckets[i]):
        continue
    indices = [i * len(buckets) + 1]
    response = query(indices)
    buckets[i].append(response[0])

    # Check if we have all the elements in this bucket
    while len(buckets[i]) < len(buckets):
        indices = [i * len(buckets) + j + 1 for j in range(len(buckets[i]), len(buckets))]
        response = query(indices)

        # Add elements to bucket
        for j, x in enumerate(response):
            if x < smallest:
                continue
            if x in buckets[i]:
                continue
            buckets[i].append(x)

        # Sort the bucket if we have all the elements
        if len(buckets[i]) == len(buckets):
            buckets[i].sort()

# Reconstruct the full list
result = []
for b in buckets:
    result.extend(b)
print("! " + " ".join(str(x) for x in result), flush=True)
