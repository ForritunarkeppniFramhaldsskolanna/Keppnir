import sys

line = sys.stdin.readline().rstrip('\n')
if len(line) > 1000:
    sys.stdout.write(line)
    sys.stdout.write('\n')
    sys.exit(0)
s = ""
pos = 0
for c in line:
    if c == 'L':
        pos -= 1
    elif c == 'R':
        pos += 1
    elif c == 'B':
        pos -= 1
        s = s[:pos] + s[pos+1:]
    else:
        s = s[:pos] + c + s[pos:]
        pos += 1
sys.stdout.write(s)
sys.stdout.write('\n')
