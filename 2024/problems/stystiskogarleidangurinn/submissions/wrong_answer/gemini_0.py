#!/usr/bin/python3
import heapq


def shortest_jungle_clear(n, m, s, monster_times, paths):
    graph = [[] for _ in range(n + 1)]  # Adjacency list
    for u, v, t in paths:
        graph[u].append((v, t))

    distances = [float("inf")] * (n + 1)  # Initialize distances
    distances[1] = 0
    smites_left = s
    priority_queue = [(0, 1)]  # (distance, monster)

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        if current_distance > distances[current_node]:  # Already found a shorter path
            continue

        for neighbor, travel_time in graph[current_node]:
            potential_distance = current_distance + travel_time

            if smites_left > 0 and potential_distance > monster_times[neighbor - 1]:
                # Use a smite
                potential_distance = current_distance
                smites_left -= 1

            if potential_distance < distances[neighbor]:
                distances[neighbor] = potential_distance
                heapq.heappush(priority_queue, (potential_distance, neighbor))

    # All monsters visited, find the final distance
    return distances[n]


# Example usage with Sample Input 1
n, m, s = map(int, input().split())
monster_times = list(map(int, input().split()))
paths = []
for _ in range(m):
    u, v, t = map(int, input().split())
    paths.append([u, v, t])

shortest_time = shortest_jungle_clear(n, m, s, monster_times, paths)
print(shortest_time)  # Output: 13
