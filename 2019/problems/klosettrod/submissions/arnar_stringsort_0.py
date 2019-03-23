import sys
n = int(sys.stdin.readline().rstrip('\n'))
arr = sys.stdin.readline().split()
ind = [i+1 for i in range(n)]
sys.stdout.write("%s\n" % ' '.join(sorted(ind, key=lambda x: arr[x-1])))
