import sys
n = int(sys.stdin.readline().rstrip('\n'))
arr = list(map(int, sys.stdin.readline().split()))
sys.stdout.write("%d %d\n" % (max(arr), min(arr)))
