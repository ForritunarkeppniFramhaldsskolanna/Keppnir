#!/usr/bin/python3
import collections

r, c = map(int, input().strip().split())
q = int(input())
todo_set, todo_queue = set(), collections.deque()
inp = [tuple(map(int, input().strip().split())) for i in range(q)][::-1]
t, x, y = 0, 0, 0
while len(inp) > 0 or len(todo_queue) > 0:
    if len(todo_queue) == 0 and inp[-1][0] > t:
        t = inp[-1][0]
    while len(inp) > 0 and inp[-1][0] <= t:
        todo_queue.appendleft((inp[-1][1], inp[-1][2]))
        todo_set.add((inp[-1][1], inp[-1][2]))
        inp.pop()
    if (x, y) in todo_set:
        print(t, x, y)
        todo_set.remove((x, y))
    while len(todo_queue) > 0 and todo_queue[-1] not in todo_set:
        todo_queue.pop()
    if len(todo_queue) == 0:
        continue
    if todo_queue[-1][0] > x:
        x += 1
    if todo_queue[-1][0] < x:
        x -= 1
    if todo_queue[-1][1] > y:
        y += 1
    if todo_queue[-1][1] < y:
        y -= 1
    t += 1

