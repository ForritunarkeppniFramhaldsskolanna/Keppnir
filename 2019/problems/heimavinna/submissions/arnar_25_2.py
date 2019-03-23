import sys

line = sys.stdin.readline().rstrip('\n')
cnt = len(line.split(';'))

sys.stdout.write("%d\n" % cnt)
