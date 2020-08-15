#!/usr/bin/env python3

n,m = [int(x) for x in input().split()]
arr = []
for x in range(m):
    t = input().split()
    arr.append((int(t[0]), t[1] ))

arr.sort()

memo = {}
def dp(at_list, at_longest, at_turn):
    global n
    global m
    global memo
    global arr

    thing = (at_list, at_longest, at_turn)

    if thing in memo:
        return memo[thing]

    if at_list >= m:
        return True

    if at_longest == -1:
        memo[thing] =  dp(at_list+1, at_list, 0) or dp(at_list+1, at_list, 1)
    else:
        good = False
        other = "?"*(arr[at_longest][0]-1)
        if at_turn == 1:
            other += arr[at_longest][1][::-1]
        else:
            other += arr[at_longest][1]

        # Don't flip
        st = "?"*(arr[at_list][0]-1) + arr[at_list][1]
        same = True
        for x in range(min(len(st), len(other))):
            if st[x] == '?' or other[x] == '?':
                continue
            if st[x] != other[x]:
                same = False

        if same:
            longe = at_longest
            flipped = at_turn
            if len(st) > len(other):
                longe = at_list
                flipped = 0
            good = good or dp(at_list+1, longe, flipped)


        # Flip
        st = "?"*(arr[at_list][0]-1) + arr[at_list][1][::-1]
        same = True
        for x in range(min(len(st), len(other))):
            if st[x] == '?' or other[x] == '?':
                continue
            if st[x] != other[x]:
                same = False

        if same:
            longe = at_longest
            flipped = at_turn
            if len(st) > len(other):
                longe = at_list
                flipped = 1
            good = good or dp(at_list+1, longe, flipped)
        memo[thing] = good

    return memo[thing]

solution = []
def backtrack(at_list, at_longest, at_turn):
    global n
    global m
    global memo
    global arr
    global solution

    thing = (at_list, at_longest, at_turn)

    if at_list >= m:
        return 

    if at_longest == -1:
        if dp(at_list+1, at_list,0):
            solution.append(0)
            backtrack(at_list+1,at_list,0)
            return
        else:
            solution.append(1)
            backtrack(at_list+1,at_list,1)
            return
    else:
        good = False
        other = "?"*(arr[at_longest][0]-1)
        if at_turn == 1:
            other += arr[at_longest][1][::-1]
        else:
            other += arr[at_longest][1]

        # Don't flip
        st = "?"*(arr[at_list][0]-1) + arr[at_list][1]
        same = True
        for x in range(min(len(st), len(other))):
            if st[x] == '?' or other[x] == '?':
                continue
            if st[x] != other[x]:
                same = False

        if same:
            longe = at_longest
            flipped = at_turn
            if len(st) > len(other):
                longe = at_list
                flipped = 0
            if dp(at_list+1,longe,flipped):
                solution.append(0)
                backtrack(at_list+1, longe, flipped)
                return


        # Flip
        st = "?"*(arr[at_list][0]-1) + arr[at_list][1][::-1]
        same = True
        for x in range(min(len(st), len(other))):
            if st[x] == '?' or other[x] == '?':
                continue
            if st[x] != other[x]:
                same = False

        if same:
            longe = at_longest
            flipped = at_turn
            if len(st) > len(other):
                longe = at_list
                flipped = 1
            if dp(at_list+1, longe, flipped):
                solution.append(1)
                backtrack(at_list+1, longe, flipped)
                return



val = dp(0,-1,-1)
if val:
    sol = []
    for x in range(n):
        sol.append('C')
    backtrack(0,-1,-1)
    for x in range(m):
        start = int(arr[x][0])-1
        st = arr[x][1]
        if solution[x] == 1:
            st = st[::-1]
        for y in range(start, start+len(st)):
            sol[y] = st[y-start]
    print(''.join(sol))
else:
    print("Villa")



