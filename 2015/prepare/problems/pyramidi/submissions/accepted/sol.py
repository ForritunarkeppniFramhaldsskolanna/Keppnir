
n = int(raw_input())

cur = 0
height = 0
while cur + (height + 1) <= n:
    height += 1
    cur += height

print('%d %d' % (height, n - cur))

