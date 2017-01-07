import sys
line = sys.stdin.readline().split()
text = sys.stdin.readline()
td = line[0]
if td == 't':
    c1, c2 = line[1], line[2]
    print(''.join([ c2 if c == c1 else c for c in text ]))
else:
    c1 = line[1]
    print(''.join([ '' if c == c1 else c for c in text ]))
