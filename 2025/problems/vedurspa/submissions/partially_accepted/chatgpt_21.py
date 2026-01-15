import sys


def linear_regression(data):
    """
    Performs a simple linear regression on a list of (x, y) points.
    Returns (slope, intercept). If only one data point is provided, returns slope 0.
    If no data is available, returns (None, None).
    """
    n = len(data)
    if n == 0:
        return None, None
    if n == 1:
        return 0, data[0][1]
    sum_x = sum(x for x, y in data)
    sum_y = sum(y for x, y in data)
    sum_xy = sum(x * y for x, y in data)
    sum_x2 = sum(x * x for x, y in data)
    denom = n * sum_x2 - sum_x * sum_x
    if abs(denom) < 1e-9:
        slope = 0
    else:
        slope = (n * sum_xy - sum_x * sum_y) / denom
    intercept = (sum_y - slope * sum_x) / n
    return slope, intercept


def unwrap_angles(angles):
    """
    Unwraps a list of angles (in degrees) so that jumps larger than 180 degrees are removed.
    Returns a new list of unwrapped angles.
    """
    if not angles:
        return []
    unwrapped = [angles[0]]
    for angle in angles[1:]:
        diff = angle - unwrapped[-1]
        # Adjust diff to be in the range [-180, 180)
        while diff > 180:
            diff -= 360
        while diff < -180:
            diff += 360
        unwrapped.append(unwrapped[-1] + diff)
    return unwrapped


def solve():
    data = sys.stdin.read().strip().splitlines()
    if not data:
        return

    try:
        n, m = map(int, data[0].split())
    except Exception:
        return

    # The second line is metadata; we don't need it.
    measurements = data[2 : 2 + n]

    # Prepare lists for each variable as (time_index, value)
    temp_data = []
    wind_speed_data = []
    humidity_data = []
    wind_dir_times = []
    wind_dir_angles = []

    for i, line in enumerate(measurements):
        parts = line.split()
        if len(parts) < 4:
            continue
        # Temperature: float, one decimal place
        if parts[0] != "-":
            try:
                temp = float(parts[0])
                temp_data.append((i, temp))
            except Exception:
                pass
        # Wind direction: integer degrees
        if parts[1] != "-":
            try:
                wd = float(parts[1])
                wind_dir_times.append(i)
                wind_dir_angles.append(wd)
            except Exception:
                pass
        # Wind speed: float, one decimal place
        if parts[2] != "-":
            try:
                ws = float(parts[2])
                wind_speed_data.append((i, ws))
            except Exception:
                pass
        # Humidity: integer
        if parts[3] != "-":
            try:
                hum = float(parts[3])
                humidity_data.append((i, hum))
            except Exception:
                pass

    # Compute regression parameters for temperature, wind speed, and humidity.
    temp_slope, temp_intercept = linear_regression(temp_data)
    ws_slope, ws_intercept = linear_regression(wind_speed_data)
    hum_slope, hum_intercept = linear_regression(humidity_data)

    # For wind direction, first unwrap the angles, then compute regression on unwrapped values.
    if wind_dir_angles:
        unwrapped_angles = unwrap_angles(wind_dir_angles)
        # Create pairs (time, unwrapped_angle)
        wind_dir_data = list(zip(wind_dir_times, unwrapped_angles))
        wd_slope, wd_intercept = linear_regression(wind_dir_data)
    else:
        wd_slope, wd_intercept = None, None

    output_lines = []
    for h in range(m):
        forecast_index = n + h

        # Temperature forecast
        if temp_slope is None:
            temp_pred = None
        else:
            temp_pred = temp_slope * forecast_index + temp_intercept

        # Wind speed forecast
        if ws_slope is None:
            ws_pred = None
        else:
            ws_pred = ws_slope * forecast_index + ws_intercept

        # Humidity forecast
        if hum_slope is None:
            hum_pred = None
        else:
            hum_pred = hum_slope * forecast_index + hum_intercept

        # Wind direction forecast: use regression on unwrapped angles and wrap back to [0, 360)
        if wd_slope is None:
            wd_pred = None
        else:
            wd_pred = wd_slope * forecast_index + wd_intercept
            wd_pred = wd_pred % 360

        # Format predictions to match input specifications:
        # Temperature and wind speed: one digit after the decimal.
        # Wind direction and humidity: integers.
        temp_str = "-" if temp_pred is None else f"{temp_pred:.1f}"
        ws_str = "-" if ws_pred is None else f"{ws_pred:.1f}"
        wd_str = "-" if wd_pred is None else f"{int(round(wd_pred))}"
        hum_str = "-" if hum_pred is None else f"{int(round(hum_pred))}"

        output_lines.append(f"{temp_str} {wd_str} {ws_str} {hum_str}")

    sys.stdout.write("\n".join(output_lines))


if __name__ == "__main__":
    solve()
