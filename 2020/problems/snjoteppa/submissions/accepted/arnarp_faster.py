#!/usr/env/bin python3
n ,k = [int(x) for x in input().split()]

gata = [[],[]]
gata[0] = list(input())
gata[1] = list(input())

blocked=0

def checkBlocked(x,y):
    global blocked
    if (gata[(x+1)%2][y]=='o'):
        blocked+=1
    if (y-1>= 0 and gata[(x+1)%2][y-1]=='o'):
        blocked+=1
    if (y+1<n and gata[(x+1)%2][y+1]=='o'):
        blocked += 1

def checkUnblocked(x,y):
    global blocked
    if (gata[(x+1)%2][y]=='o'):
        blocked -=1
    if (y-1>=0 and gata[(x+1)%2][y-1]=='o'):
        blocked -=1
    if (y+1<n and gata[(x+1)%2][y+1]=='o'):
        blocked -= 1

for x in range(n):
    if(gata[0][x]=='o'):
        checkBlocked(0,x)
    if(gata[1][x]=='o'):
        checkBlocked(1,x)
blocked //= 2

for i in range(k):
    line =input().strip()
    if(line =="Q"):
        if(blocked>0):
            print("Neibb")
        else:
            print("Jebb")
    else: 
        x,y = map(int,line.split(' ')[1:])
        x,y = x-1,y-1

        if(gata[x][y] =='.'):
            gata[x][y] ='o'
            checkBlocked(x,y)
        else:
            gata[x][y] ='.'
            checkUnblocked(x,y)
