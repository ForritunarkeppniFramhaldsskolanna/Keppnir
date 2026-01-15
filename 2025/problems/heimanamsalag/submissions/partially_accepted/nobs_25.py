import heapq
import sys

n = int(sys.stdin.readline())
abt = [tuple(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
if all(abt[i][2] == 0 for i in range(n)):
    print(0)
    exit(0)
lo, hi = 1, 0
for i in range(n):
    hi += abt[i][2]
st = []
for i in range(n):
    st.append((abt[i][0], i))
st.sort()
for md in range(lo, hi + 1):
    nd = []
    st_ind = 0
    cur_day = 0
    hours_left = md
    possible = True
    while st_ind < n or len(nd) > 0:
        if st_ind < n and st[st_ind][0] <= cur_day:
            i = st[st_ind][1]
            st_ind += 1
            heapq.heappush(nd, (abt[i][1], abt[i][2]))
            continue
        if st_ind < n and len(nd) == 0:
            i = st[st_ind][1]
            st_ind += 1
            cur_day = max(abt[i][0], cur_day)
            hours_left = md
            heapq.heappush(nd, (abt[i][1], abt[i][2]))
            continue
        if cur_day > nd[0][0]:
            possible = False
            break
        until = nd[0][0]
        if st_ind < n:
            until = min(until, st[st_ind][0] - 1)
        take_1 = min(hours_left, nd[0][1])
        nd[0] = (nd[0][0], nd[0][1] - take_1)
        hours_left -= take_1
        if nd[0][1] == 0:
            heapq.heappop(nd)
            continue
        if until == cur_day:
            cur_day += 1
            hours_left = md
            continue
        take_2 = min(md * (until - cur_day), nd[0][1])
        cur_day += (take_2 + md - 1) // md
        hours_left = md - (take_2 % md)
        if take_2 % md == 0:
            hours_left = 0
        nd[0] = (nd[0][0], nd[0][1] - take_2)
        if cur_day > nd[0][0]:
            possible = False
            break
        if nd[0][1] == 0:
            heapq.heappop(nd)
    if possible:
        print(md)
        exit(0)
