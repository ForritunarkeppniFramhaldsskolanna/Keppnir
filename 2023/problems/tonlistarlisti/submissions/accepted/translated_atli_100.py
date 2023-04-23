#!/usr/bin/python3

class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.bit = [0 for _ in range(n)]

    def add(self, idx, val):
        while idx < self.n:
            self.bit[idx] += val
            idx |= idx + 1
    
    def query(self, idx):
        res = 0
        while idx >= 0:
            res += self.bit[idx]
            idx = (idx & (idx + 1)) - 1
        return res
    
    def sum(self, l, r):
        return self.query(r) - self.query(l - 1)

MAXQ = 5*10**5 + 5;


if __name__ == "__main__":
    q = int(input())
    plays = FenwickTree(MAXQ)
    lengths = FenwickTree(MAXQ)
    ids = dict()
    deleted = dict()
    length = 0
    ind = 0

    for i in range(q):
        line = input().split()
        op = line[0]
        if op == "P":
            t = int(line[1])
            if t >= length:
                plays.add(1, t // length)
                plays.add(ind + 1, -(t // length))
                t %= length
            if t >= lengths.sum(ind, ind):
                l, r = 1, ind
                while r > l:
                    m = l + (r - l) // 2
                    fm = lengths.sum(m, ind)
                    if fm > t:
                        l = m + 1
                    else:
                        r = m
                plays.add(l, 1)
                plays.add(ind + 1, -1);
        elif op == "L":
            s = line[1]
            ln = int(line[2])
            if s in ids:
                play = plays.sum(1, ids[s])
                deleted[s] = play
                time = lengths.sum(ids[s], ids[s])
                length -= time
                lengths.add(ids[s], -time)
                del ids[s]
            else:
                ind += 1
                ids[s] = ind
                lengths.add(ind, ln)
                if s in deleted:
                    plays.add(ind, deleted[s])
                    plays.add(ind + 1, -deleted[s])
                    del deleted[s]
                length += ln
        elif op == "Q":
            s = line[1]
            if s in ids:
                print(plays.sum(1, ids[s]))
            elif s in deleted:
                print(deleted[s])
            else:
                print(0)
