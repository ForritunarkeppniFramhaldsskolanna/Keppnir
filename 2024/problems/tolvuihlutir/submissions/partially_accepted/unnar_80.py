#!/usr/bin/python3
from collections import defaultdict
import sys
    
n, k, p = map(int,input().split())
parts = list(input().split())

dic = defaultdict(list)
for i in range(n):
    part, cost, power = input().split()
    cost, power = int(cost), int(power)
    dic[part].append((cost, power))
    
if len(dic) < len(parts):
    print("O nei!")
    sys.exit(0)

cost = 0
mn_power = 10**10
part_index = list()
for i, part in enumerate(parts):
    dic[part] = sorted(dic[part])
    c, power = dic[part][0]
    cost += c
    if mn_power > power:
        mn_power = power
        mn_part = i
    part_index.append((power, c, i, 0))

if cost > p:
    print("O nei!")
else:
    while True:
        part_index = sorted(part_index)
        power, c, i, j = part_index[0]
        if j+1 == len(dic[parts[i]]):
            break
        nxt_c, nxt_p = dic[parts[i]][j+1]
        if cost+nxt_c-c <= p:
            if nxt_p > power:
                cost += nxt_c-c
                if len(parts) > 1:
                    mn_power = min(nxt_p, part_index[1][0])
                else:
                    mn_power = nxt_p
                part_index[0] = (nxt_p, nxt_c, i, j+1)
            else:
                part_index[0] = (power, c, i, j+1)
        else:
            break
    print(mn_power)
        
