from collections import deque


def difference(series, interval):
    return [series[i] - series[i - interval] for i in range(interval, len(series))]


def inverse_difference(last_observation, forecast, interval):
    return forecast + last_observation


def mean(values):
    return sum(values) / len(values)


def optimize_arima_coefficients(series, p, q):
    """
    Finds the best AR and MA coefficients for the given series and model order.
    Uses a basic grid search to minimize the sum of squared errors.
    """
    from itertools import product

    def calculate_sse(ar_params, ma_params):
        ar_terms = deque([0] * p, maxlen=p)
        residuals = deque([0] * q, maxlen=q)

        sse = 0
        avg = mean(series)
        for i in range(len(series)):
            ar_part = sum(ar * coeff for ar, coeff in zip(ar_terms, ar_params))
            ma_part = sum(residual * coeff for residual, coeff in zip(residuals, ma_params))
            prediction = ar_part + ma_part + avg
            if i < len(series):
                residual = series[i] - prediction
                sse += residual**2
                ar_terms.append(series[i])
                residuals.append(residual)
        return sse

    # Define ranges for coefficients to search over (simplistic)
    coeff_range = [i / 10.0 for i in range(-10, 11)]
    best_sse = float("inf")
    best_ar_params = [0] * p
    best_ma_params = [0] * q

    for ar_params in product(coeff_range, repeat=p):
        for ma_params in product(coeff_range, repeat=q):
            sse = calculate_sse(ar_params, ma_params)
            if sse < best_sse:
                best_sse = sse
                best_ar_params = ar_params
                best_ma_params = ma_params

    return best_ar_params, best_ma_params


def predict_arima(series, p, d, q, steps=1):
    if d > 0:
        original_series = series.copy()
        series = difference(series, 1)

    ar_terms = deque([0] * p, maxlen=p)
    residuals = deque([0] * q, maxlen=q)

    # Optimize AR and MA coefficients
    ar_params, ma_params = optimize_arima_coefficients(series, p, q)

    avg = mean(series)

    def predict_next():
        ar_part = sum(ar * coeff for ar, coeff in zip(ar_terms, ar_params))
        ma_part = sum(residual * coeff for residual, coeff in zip(residuals, ma_params))
        return ar_part + ma_part + avg

    predictions = []

    for _ in range(steps):
        next_value = predict_next()
        if d > 0:
            next_value = inverse_difference(original_series[-1], next_value, 1)
            original_series.append(next_value)

        predictions.append(next_value)

        ar_terms.append(series[-1] if len(series) else 0)
        residual = 0 if not series else next_value - series[-1]
        residuals.append(residual)

        series.append(next_value)

    return predictions


# Example usage
if __name__ == "__main__":
    import sys

    # Read input
    n, m = map(int, sys.stdin.readline().strip().split())
    metadata = sys.stdin.readline().strip()

    temperature_series = []
    wind_direction_series = []
    wind_speed_series = []
    humidity_series = []

    for _ in range(n):
        temp, wind_dir, wind_speed, humidity = sys.stdin.readline().strip().split()
        try:
            temperature_series.append(float(temp))
        except Exception:
            temperature_series.append(temperature_series[-1])
        try:
            wind_direction_series.append(int(wind_dir))
        except Exception:
            wind_direction_series.append(wind_direction_series[-1])
        try:
            wind_speed_series.append(float(wind_speed))
        except Exception:
            wind_speed_series.append(wind_speed_series[-1])
        try:
            humidity_series.append(int(humidity))
        except Exception:
            humidity_series.append(humidity_series[-1])

    # ARIMA parameters
    p, d, q = 1, 0, 1  # ARIMA(p, d, q) model

    # Predict future values for each series
    temperature_forecasts = predict_arima(temperature_series, p, d, q, m)
    wind_direction_forecasts = predict_arima(wind_direction_series, p, d, q, m)
    wind_speed_forecasts = predict_arima(wind_speed_series, p, d, q, m)
    humidity_forecasts = predict_arima(humidity_series, p, d, q, m)

    # Output results in the specified format
    for i in range(m):
        temp = f"{temperature_forecasts[i]:.1f}" if i < len(temperature_forecasts) else "-"
        wind_dir = f"{int(round(wind_direction_forecasts[i])) % 360}" if i < len(wind_direction_forecasts) else "-"
        wind_speed = f"{wind_speed_forecasts[i]:.1f}" if i < len(wind_speed_forecasts) else "-"
        humidity = f"{int(round(humidity_forecasts[i]))}" if i < len(humidity_forecasts) else "-"
        print(f"{temp} {wind_dir} {wind_speed} {humidity}")
