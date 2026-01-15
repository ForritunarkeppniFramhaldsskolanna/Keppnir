def get_value(x):
    return (2 * (x**2) + 224 * x + 795) ** 2 // 100


n = int(input())

x = 0

while n > get_value(x):
    x += 1

print(x)
