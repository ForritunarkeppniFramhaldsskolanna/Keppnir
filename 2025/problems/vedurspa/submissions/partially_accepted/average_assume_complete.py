n, m = map(int, input().split())
input()
temperature, direction, force, humidity = 0, 0, 0, 0
for i in range(n):
    try:
        a, b, c, d = map(float, input().split())
    except Exception:
        continue
    temperature += a
    direction += b
    force += c
    humidity += d
temperature /= n
direction /= n
force /= n
humidity /= n

direction = int(round(direction)) % 360
humidity = int(round(humidity))
for i in range(m):
    print(f"{temperature} {direction} {force} {humidity}")
