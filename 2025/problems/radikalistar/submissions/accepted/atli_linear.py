#!/usr/bin/python3
import sys

n, q = map(int, sys.stdin.readline().strip().split())

locs = list(range(n))
ord_elem = list(range(n))
sent = [-1 for _ in range(n)]
set_ind = [0 for _ in range(n)]
ranges = [(0, n - 1)]
reuse = []
nonz = 1

for _ in range(q):
    args = sys.stdin.readline().strip().split()
    if args[0] == "r":
        to_fix = []
        for arg in args[2:]:
            it = int(arg) - 1
            ind = set_ind[it]
            sz = ranges[ind][1] - ranges[ind][0] + 1
            if sz == 1 and sent[ind] == -1:
                continue
            if sent[ind] == -1:
                to_fix.append(ind)
                new_ind = len(ranges)
                nonz += 1
                if len(reuse) > 0:
                    new_ind = reuse[-1]
                    reuse.pop()
                else:
                    ranges.append((-1, -1))
                ranges[new_ind] = (ranges[ind][1] + 1, ranges[ind][1])
                sent[ind] = new_ind
            ranges[sent[ind]] = (ranges[sent[ind]][0] - 1, ranges[sent[ind]][1])
            ranges[ind] = (ranges[ind][0], ranges[ind][1] - 1)
            if ranges[ind][1] < ranges[ind][0]:
                reuse.append(ind)
                nonz -= 1
            to_swp = ord_elem[ranges[sent[ind]][0]]
            locs[it], locs[to_swp] = locs[to_swp], locs[it]
            ord_elem[locs[it]], ord_elem[locs[to_swp]] = ord_elem[locs[to_swp]], ord_elem[locs[it]]
            set_ind[it] = sent[ind]
        for x in to_fix:
            sent[x] = -1
    elif args[0] == "s":
        sys.stdout.write(str(nonz) + "\n")
    else:
        x = int(args[1]) - 1
        s = set_ind[x]
        sys.stdout.write(" ".join(str(ord_elem[y] + 1) for y in range(ranges[s][0], ranges[s][1] + 1)))
        sys.stdout.write("\n")
