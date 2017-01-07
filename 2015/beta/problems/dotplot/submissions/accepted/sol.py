import sys
lines = sys.stdin.readlines()

for i in range(len(lines)):
    lines[i] = lines[i][:-1]

for i in range(len(lines[0])):
    for j in range(len(lines)):
        if lines[j][i] == '|':
            print('%s: %d' % (lines[-1][i], len(lines) - j - 1))
            break

