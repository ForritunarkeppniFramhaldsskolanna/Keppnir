import sys
n = int(sys.stdin.readline().rstrip('\n'))
arr = list(map(int, sys.stdin.readline().split()))
sys.stdout.write("%d %d\n" % (arr[-1], arr[0]))
