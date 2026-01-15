import sys

# Read input data
n, k = map(int, sys.stdin.readline().split())
sys.stdin.readline()
data = []


def float_or_missing(x):
    return 0 if x == "-" else float(x)


for _ in range(n):
    line = list(map(float_or_missing, sys.stdin.readline().split()))
    data.append(line)


# Forecasting code here...
def forecast(data):
    n = len(data)

    # Forecasting values using moving averages
    forecast_data = []

    for i in range(k):
        weight_sum = 0
        weighted_sum_temperature = 0
        weighted_sum_wind_direction = 0
        weighted_sum_wind_force = 0
        weighted_sum_humidity = 0

        for j in range(n - 1, max(0, n - 10), -1):
            weight = 0.8 ** (j - (n - 1))
            temperature = data[j][0]
            wind_direction = data[j][1] % 360
            wind_force = data[j][2]
            humidity = data[j][3]

            weight_sum += weight
            weighted_sum_temperature += weight * temperature
            weighted_sum_wind_direction += weight * wind_direction
            weighted_sum_wind_force += weight * wind_force
            weighted_sum_humidity += weight * humidity

        forecast_point = [
            weighted_sum_temperature / weight_sum,
            weighted_sum_wind_direction / weight_sum,
            weighted_sum_wind_force / weight_sum,
            weighted_sum_humidity / weight_sum,
        ]

        forecast_data.append(forecast_point)

    return forecast_data


forecasted_data = forecast(data)

for point in forecasted_data:
    print(" ".join(map(str, point)))
