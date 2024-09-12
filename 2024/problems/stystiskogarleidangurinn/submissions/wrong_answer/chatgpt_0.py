#!/usr/bin/python3
from heapq import heappop, heappush
from sys import stdin
from itertools import combinations

def min_time_to_clear_jungle(n, m, s, monster_times, paths):
    # Initialize adjacency list for graph
    adj = {i: [] for i in range(n)}
    for u, v, t in paths:
        adj[u-1].append((v-1, t))
        adj[v-1].append((u-1, t))

    # Apply Dijkstra's algorithm to find shortest paths from every monster to every other monster
    def dijkstra(start):
        dist = [float('inf')] * n
        dist[start] = 0
        queue = [(0, start)]
        while queue:
            d, current = heappop(queue)
            if d > dist[current]:
                continue
            for neighbor, weight in adj[current]:
                if dist[neighbor] > d + weight:
                    dist[neighbor] = d + weight
                    heappush(queue, (dist[neighbor], neighbor))
        return dist

    # Precompute the shortest paths between all pairs of monsters
    all_pairs_shortest_path = [dijkstra(i) for i in range(n)]

    # Dynamic programming to find minimum time with smite usage
    # dp[mask][i] = minimum time to defeat monsters in mask, ending at monster i
    dp = [[float('inf')] * n for _ in range(1 << n)]
    dp[1][0] = 0  # Start with the first monster defeated

    for mask in range(1 << n):
        for u in range(n):
            if mask & (1 << u) == 0:  # If monster u is not yet defeated
                continue
            for v in range(n):
                if mask & (1 << v):  # If monster v is already defeated
                    continue
                new_mask = mask | (1 << v)
                time_to_defeat = 0 if s > 0 else monster_times[v]
                dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + all_pairs_shortest_path[u][v] + time_to_defeat)

    # Calculate the minimum time to clear the jungle with the optimal use of smite
    min_time = float('inf')
    for i in range(n):
        min_time = min(min_time, dp[(1 << n) - 1][i])

    # If s > 0, smite can be used to instantly defeat any remaining monster
    if s > 0:
        min_time -= max(monster_times)  # Assume smite is used on the monster with the longest defeat time

    return min_time

# Read input
n, m, s = map(int, input().split())
monster_times = list(map(int, input().split()))
paths = [tuple(map(int, input().split())) for _ in range(m)]
print(min_time_to_clear_jungle(n, m, s, monster_times, paths))
