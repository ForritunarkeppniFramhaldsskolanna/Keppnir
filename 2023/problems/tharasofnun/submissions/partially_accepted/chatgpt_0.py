#!/usr/bin/python3
# Note: I removed output like "Please enter a number"
import heapq

# Function to calculate the Manhattan distance between two points
def manhattan_distance(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

class KelpRobot:
    def __init__(self, c, r):
        self.c = c
        self.r = r
        self.current_pos = (0, 0)
        self.time = 0
        self.harvest_queue = []

    def add_query(self, t, x, y):
        heapq.heappush(self.harvest_queue, (t, x, y))

    def harvest(self):
        while self.harvest_queue:
            t, x, y = heapq.heappop(self.harvest_queue)
            if t > self.time:
                self.time += manhattan_distance(self.current_pos, (x, y))
                self.current_pos = (x, y)
                print(self.time, *self.current_pos)

c, r = map(int, input().split())
robot = KelpRobot(c, r)
q = int(input())
for _ in range(q):
    t, x, y = map(int, input().split())
    robot.add_query(t, x, y)
robot.harvest()
