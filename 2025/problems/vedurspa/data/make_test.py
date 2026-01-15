import sys

HOUR = 1
DAY = 24 * HOUR
WEEK = 7 * DAY
FORTNIGHT = 2 * WEEK
MONTH = 30 * DAY
YEAR = 365 * DAY
FOUR_YEARS = 4 * YEAR + DAY

MISSING = "-"
DURATIONS = {
    "hour": HOUR,
    "day": DAY,
    "week": WEEK,
    "fortnight": FORTNIGHT,
    "month": MONTH,
    "year": YEAR,
    "fouryears": FOUR_YEARS,
}

station_data_file = "../" + sys.argv[1]
train_multiplier = int(sys.argv[2])
train_duration = train_multiplier * DURATIONS[sys.argv[3]]
forecast_multiplier = int(sys.argv[4])
forecast_duration = forecast_multiplier * DURATIONS[sys.argv[5]]
is_answer = sys.argv[6] == "answer"

input_answer = "answer" if is_answer else "input"
sys.stderr.write(
    f"Generating {input_answer} for {station_data_file} with {train_multiplier} {sys.argv[3]} training data and {forecast_multiplier} {sys.argv[5]}.\n"
)

with open(station_data_file) as f:
    available = f.readline().strip()
    latitude, longtitude, elevation = f.readline().split()
    available = int(available)
    latitude = float(latitude)
    longtitude = float(longtitude)
    elevation = float(elevation)
    data_points = []
    for _ in range(available):
        date, time, temp, direction, speed, humidity = f.readline().strip().split()
        temp = MISSING if temp == MISSING else float(temp)
        direction = MISSING if direction == MISSING else int(direction)
        speed = MISSING if speed == MISSING else float(speed)
        humidity = MISSING if humidity == MISSING else int(humidity)
        data_points.append((date, time, temp, direction, speed, humidity))


if is_answer:
    output = data_points[-forecast_duration:]
else:
    output = data_points[-(train_duration + forecast_duration) : -forecast_duration]
    start_date = output[0][0]
    start_time = output[0][1]
    train_duration = len(output)
    print(f"{train_duration} {forecast_duration}")
    print(f"{latitude} {longtitude} {elevation} {start_date} {start_time}")
for date, time, temp, direction, speed, humidity in output:
    print(f"{temp} {direction} {speed} {humidity}")
