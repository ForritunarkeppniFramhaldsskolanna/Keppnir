import sys
n = int(sys.stdin.readline().rstrip('\n'))
arr = list(map(int, sys.stdin.readline().split()))
ind = [i+1 for i in range(n)]
sys.stdout.write("%s\n" % ' '.join(map(str, sorted(ind, key=lambda x: arr[x-1], reverse=True))))
