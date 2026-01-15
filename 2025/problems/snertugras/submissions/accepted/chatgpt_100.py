import sys
from collections import deque


def main():
    # Read input data
    data = sys.stdin.read().splitlines()
    if not data:
        return
    h, w = map(int, data[0].split())
    grid = data[1:]

    # Locate the starting cell 'S'
    start = None
    for i in range(h):
        for j in range(w):
            if grid[i][j] == "S":
                start = (i, j)
                break
        if start is not None:
            break

    # If starting cell not found, output the failure message (should not happen as per problem statement)
    if start is None:
        print("thralatlega nettengdur")
        return

    # Initialize BFS with the starting position and distance 0
    dq = deque()
    dq.append((start[0], start[1], 0))

    # Create a visited array to avoid processing cells more than once
    visited = [[False] * w for _ in range(h)]
    visited[start[0]][start[1]] = True

    # Perform BFS
    while dq:
        i, j, steps = dq.popleft()

        # If we reached a cell with grass, print the distance and exit
        if grid[i][j] == "G":
            print(steps)
            return

        # Explore all four possible directions
        for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ni, nj = i + di, j + dj
            if ni < 0 or ni >= h or nj < 0 or nj >= w:
                continue  # Out of bounds
            if visited[ni][nj]:
                continue  # Already visited
            if grid[ni][nj] == "#":
                continue  # Wall, cannot pass
            visited[ni][nj] = True
            dq.append((ni, nj, steps + 1))

    # If no grass cell was reached, print the message for being "terminally online"
    print("thralatlega nettengdur")


if __name__ == "__main__":
    main()
