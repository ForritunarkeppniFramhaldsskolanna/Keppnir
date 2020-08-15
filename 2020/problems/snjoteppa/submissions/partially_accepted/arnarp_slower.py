#!/usr/env/bin python3
n ,k = [int(x) for x in input().split()]

gata = [[],[]]
gata[0] = list(input())
gata[1] = list(input())


def checkBlocked():
    for z in range(n):
        if(gata[0][z]=='o'):
            if((gata[1][z]=='o') or (z+1 < n and gata[1][z+1] =='o')):
                return True
        elif(gata[1][z]=='o'):
            if(z+1 < n and gata[0][z+1] =='o'):
                return True
    return False


for i in range(k):
    line =input().strip()
    if(line =="Q"):
        if(checkBlocked()):
            print("Neibb")
        else:
            print("Jebb")
    else: 
        x,y = map(int,line.split(' ')[1:])
        x,y = x-1,y-1

        if(gata[x][y] =='.'):
            gata[x][y] ='o'
        else:
            gata[x][y] ='.'
