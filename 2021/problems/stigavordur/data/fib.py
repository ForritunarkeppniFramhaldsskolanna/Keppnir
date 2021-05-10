x = 1
y = 1
while x + y < 10**9:
    x, y = y, x + y
print(x, y)
