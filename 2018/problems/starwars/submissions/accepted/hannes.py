import sys

n = int(sys.stdin.readline())

line = [int(i) for i in sys.stdin.readline().split()]

line = sorted(line)

first = (n//3)
second = (2*(n//3))
third = n

sec1 = list(map(str, line[0:first]))
sec2 = list(map(str, line[first:second]))
sec3 = list(map(str, line[second:third]))

print(" ".join(sec2 + sec1 + sec3))