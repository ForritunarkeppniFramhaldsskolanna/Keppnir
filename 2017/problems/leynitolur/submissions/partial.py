import sys

a = 230309227
b = 68431307
for line in sys.stdin.read().strip().split():
    x = int(line)
    print((x - b) // a)

