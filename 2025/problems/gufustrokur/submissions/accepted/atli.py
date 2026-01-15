x = int(input())
y = int(input())
print(min((x - y) % 360, (y - x) % 360))
