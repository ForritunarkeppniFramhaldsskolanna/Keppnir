#!/usr/bin/python3
def process_queries(n, q, names, queries):
    # Initialize scores for each participant
    scores = {name: 0 for name in names}

    for query in queries:
        parts = query.split()
        if parts[0] == "!":
            # Update the scores based on the query
            k = int(parts[1])
            for i in range(k):
                name, score = parts[2+i*2], int(parts[3+i*2])
                scores[name] += score
        elif parts[0] == "?":
            # Calculate and print the ranking and score for the requested participant
            name = parts[1]
            score_list = sorted(scores.values(), reverse=True)
            rank = score_list.index(scores[name]) + 1  # 1-based ranking
            # Handle ties by assigning the highest rank among tied participants
            while rank > 1 and scores[name] == score_list[rank-2]:
                rank -= 1
            print(f"{rank} {scores[name]}")

if __name__ == "__main__":
    # Read input
    n, q = map(int, input().split())
    names = input().split()
    queries = [input() for _ in range(q)]

    # Process queries
    process_queries(n, q, names, queries)

