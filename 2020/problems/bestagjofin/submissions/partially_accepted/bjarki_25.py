import sys

n = int(sys.stdin.readline())

a_name, a_score = sys.stdin.readline().split()
a_score = int(a_score)

b_name, b_score = sys.stdin.readline().split()
b_score = int(b_score)

c_name, c_score = sys.stdin.readline().split()
c_score = int(c_score)


if a_score > b_score:
    if a_score > c_score:
        print(a_name)
    else:
        print(c_name)
else:
    if b_score > c_score:
        print(b_name)
    else:
        print(c_name)

