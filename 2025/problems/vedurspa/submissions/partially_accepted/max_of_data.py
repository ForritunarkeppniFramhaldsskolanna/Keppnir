n, m = map(int, input().split())
metadata = input()
data = []
min_temp = 50.0
max_temp = -50.0
min_direction = 360
max_direction = 0
min_force = 80.0
max_force = 0.0
min_humidity = 110
max_humidity = 0
for i in range(n):
    line = input()
    parts = line.split()
    if parts[0] != "-":
        min_temp = min(min_temp, float(parts[0]))
        max_temp = max(max_temp, float(parts[0]))
    if parts[1] != "-":
        min_direction = min(min_direction, int(parts[1]))
        max_direction = max(max_direction, int(parts[1]))
    if parts[2] != "-":
        min_force = min(min_force, float(parts[2]))
        max_force = max(max_force, float(parts[2]))
    if parts[3] != "-":
        min_humidity = min(min_humidity, int(parts[3]))
        max_humidity = max(max_humidity, int(parts[3]))
for i in range(m):
    temp = max_temp
    direction = max_direction
    force = max_force
    humidity = max_humidity
    print(f"{temp} {direction} {force} {humidity}")
