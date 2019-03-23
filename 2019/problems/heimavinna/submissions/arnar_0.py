import sys

line = sys.stdin.readline().rstrip('\n')
cnt = 0
s = x.split('-')
cnt += int(s[1]) - int(s[0]) + 1

sys.stdout.write("%d\n" % cnt)
