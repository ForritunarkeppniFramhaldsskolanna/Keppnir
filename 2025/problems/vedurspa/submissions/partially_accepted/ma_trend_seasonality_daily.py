from statistics import mean

n, m = map(int, input().split())
input()


class TimeSeries:
    def __init__(self, series, indices=None):
        if indices is None:
            self.x = list(map(float, range(len(series))))
        else:
            self.x = list(indices)
        self.y = list(series)
        self.n = len(series)

    def __add__(self, other):
        assert self.x == other.x
        return self.__class__([y1 + y2 for (y1, y2) in zip(self.y, other.y)], self.x)

    def __sub__(self, other):
        assert self.x == other.x
        return self.__class__([y1 - y2 for (y1, y2) in zip(self.y, other.y)], self.x)

    def __iter__(self):
        yield from self.y.__iter__()

    def __len__(self):
        return self.n

    def subseries(self, start=None, end=None):
        if start is None:
            start = 0
        if end is None:
            end = len(self)
        return self.__class__(self.y[start:end], self.x[start:end])

    def diff(self, k=1):
        return self.__class__([self.y[i] - self.y[i - 1] for i in range(k, self.n)])

    def trend(self):
        x_average = mean(self.x)
        y_average = mean(self.y)
        numerator = sum((self.x[i] - x_average) * (self.y[i] - y_average) for i in range(self.n))
        denominator = sum((self.x[i] - x_average) ** 2 for i in range(self.n))
        m = numerator / denominator
        b = y_average - m * x_average
        return self.__class__([m * x + b for x in self.x], self.x)

    def detrended(self):
        return self - self.trend()

    def __str__(self):
        return str(self.y[-120:])

    def seasonal_average(self, num_seasons):
        unnormalized_seasonal_average = [
            mean(self.y[j] for j in range(i, self.n, num_seasons)) for i in range(num_seasons)
        ]
        average = mean(unnormalized_seasonal_average)
        return [x - average for x in unnormalized_seasonal_average]

    def moving_average(self, alpha, window_size=None):
        result = []
        current_value = self.y[0]
        for i in range(1, self.n):
            if window_size is not None and i >= window_size:
                current_value -= self.y[i - window_size] * alpha * pow(1 - alpha, window_size - 1)
            current_value *= 1 - alpha
            current_value += alpha * self.y[i]
            if window_size is None or i + 1 >= window_size:
                result.append(current_value)
        start_ind = 0 if window_size is None else window_size - 1
        return self.__class__(result, self.x[start_ind:])


HOUR = 1
DAY = 24 * HOUR
YEAR = 365 * DAY


def predict(original, m):
    SEASONS = DAY

    # print("Original:")
    # print(original)

    moving_average = original.moving_average(0.8)
    # print("Moving average:")
    # print(moving_average)

    detrended = original - moving_average
    # print("Detrended:")
    # print(detrended)

    hour_in_day_average = detrended.seasonal_average(SEASONS)
    seasonality = TimeSeries([hour_in_day_average[i % SEASONS] for i in range(n)])
    # print("Seasonality:")
    # print(seasonality)

    deseasonalized = original - seasonality
    # print("Deseasonalized:")
    # print(deseasonalized)

    trend = deseasonalized.trend()
    # print("Trend:")
    # print(trend)

    residual = deseasonalized - trend
    # print("Residual:")
    # print(residual)

    slope = trend.diff().y[0]
    intercept = trend.y[0] - m * trend.x[0]
    base = mean(residual)

    result = []
    for i in range(n, n + m):
        trend_prediction = slope * i + intercept
        seasonality_prediction = seasonality.y[i % SEASONS]
        result.append(trend_prediction + seasonality_prediction + base)
    return result


temperature = []
direction = []
force = []
humidity = []

for i in range(n):
    a, b, c, d = input().split()
    try:
        temperature.append(float(a))
    except Exception:
        temperature.append(temperature[-1] if temperature else 0.0)
    try:
        direction.append(float(b))
    except Exception:
        direction.append(direction[-1] if direction else 0.0)
    try:
        force.append(float(c))
    except Exception:
        force.append(force[-1] if force else 0.0)
    try:
        humidity.append(float(d))
    except Exception:
        humidity.append(humidity[-1] if humidity else 0.0)


for i in range(1, n):
    diff = direction[i] - direction[i - 1]
    diff = (diff + 180) % 360 - 180
    direction[i] = direction[i - 1] + diff

temperature = TimeSeries(temperature)
direction = TimeSeries(direction)
force = TimeSeries(force)
humidity = TimeSeries(humidity)

t_p = predict(temperature, m)
d_p = predict(direction, m)
f_p = predict(force, m)
h_p = predict(humidity, m)

for t, d, f, h in zip(t_p, d_p, f_p, h_p):
    print(t, round(d) % 360, f, round(h))
