n, m = map(int, input().split())
input()
temperature, direction, force, humidity = 0, 0, 0, 0
temp_count, direction_count, force_count, humidity_count = 0, 0, 0, 0
for i in range(n):
    line = input()
    parts = line.split()
    if parts[0] != "-":
        temperature += float(parts[0])
        temp_count += 1
    if parts[1] != "-":
        direction += int(parts[1])
        direction_count += 1
    if parts[2] != "-":
        force += float(parts[2])
        force_count += 1
    if parts[3] != "-":
        humidity += int(parts[3])
        humidity_count += 1

if temp_count > 0:
    temperature /= temp_count
if direction_count > 0:
    direction /= direction_count
if force_count > 0:
    force /= force_count
if humidity_count > 0:
    humidity /= humidity_count

for i in range(m):
    print(f"{temperature} {direction} {force} {humidity}")
