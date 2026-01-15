import re
import sys
import datetime

line = input()
assert re.match("^[1-9][0-9]* [1-9][0-9]*$", line), "Error in line 1"
n, m = map(int, line.split())

line = input()
assert re.match(
    "^[1-9]?[0-9][.][0-9]{1,6} [1-9]?[0-9][.][0-9]{1,6} (0|[1-9][0-9]*)[.][0-9] \\d\\d\\d\\d-\\d\\d-\\d\\d \\d\\d[:]\\d\\d[:]\\d\\d$",
    line,
), "Error in line 2"
latitude, longtitude, elevation, date, time = line.split()
latitude = float(latitude)
longtitude = float(longtitude)
elevation = float(elevation)
date_time = datetime.datetime.fromisoformat(date + " " + time)

assert 63.0 <= latitude <= 68.0
assert 12.0 <= longtitude <= 26.0
assert 0.0 <= elevation <= 4000.0

for i in range(n):
    line = input()
    assert re.match("^(-|-?[0-9]*[.][0-9]) (-|0|[1-9][0-9]*) (-|[0-9][0-9]*[.][0-9]) (-|0|[1-9][0-9]*)$", line), (
        f"Error in line {i + 3}"
    )
    temperature, direction, force, humidity = line.split()
    if temperature != "-":
        temperature = float(temperature)
        assert -50.0 <= temperature <= 50.0, f"Error in line {i + 3}"
    if direction != "-":
        direction = int(direction)
        assert 0 <= direction <= 360, f"Error in line {i + 3}"
    if force != "-":
        force = float(force)
        assert 0.0 <= force <= 80.0, f"Error in line {i + 3}"
    if humidity != "-":
        humidity = int(humidity)
        assert 0 <= humidity <= 110, f"Error in line {i + 3}"


assert sys.stdin.read() == "", "Trailing input"

sys.exit(42)
