#!/usr/bin/python3
from collections import defaultdict

q = int(input())
playlist = []
listen_count = defaultdict(int)

for _ in range(q):
    query = input().split()
    if query[0] == 'P':
        time = int(query[1])
        while time > 0 and playlist:
            song, length = playlist[-1]
            if length <= time:
                time -= length
                listen_count[song] += 1
                playlist.pop()
            else:
                playlist[-1] = (song, length - time)
                time = 0
    elif query[0] == 'L':
        song, length = query[1], int(query[2])
        if playlist and playlist[-1][0] == song:
            playlist.pop()
        else:
            playlist.append((song, length))
    elif query[0] == 'Q':
        song = query[1]
        print(listen_count[song])

