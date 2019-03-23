import sys

line = sys.stdin.readline().rstrip('\n')
stuff = line.split(';')
sm = 0
for x in stuff:
    d = x.split('-')
    if len(d) == 1:
        sm += 1
    else:
        sm += int(d[1])-int(d[0])+1
    
sys.stdout.write("%d\n" % sm)
