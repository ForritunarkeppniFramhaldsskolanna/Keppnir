import random

from math import isnan
from statistics import mean
from statistics import StatisticsError

n, m = map(int, input().split())
input()


def mean_or_zero(L):
    try:
        return mean(x for x in L if not isnan(x))
    except StatisticsError:
        return float("nan")


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

    def integrate(self, k=1, initial_values=None):
        if initial_values is None:
            initial_values = [0.0 for _ in range(k)]
        res = list(initial_values)
        for i, x in enumerate(self.y):
            res.append(res[i] + x)
        return self.__class__(res)

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
        return str(self.y)

    def seasonal_average(self, num_seasons):
        unnormalized_seasonal_average = [
            mean_or_zero(self.y[j] for j in range(i, self.n, num_seasons)) for i in range(num_seasons)
        ]
        average = mean_or_zero(unnormalized_seasonal_average)
        normalized = [x - average for x in unnormalized_seasonal_average if not isnan(x)]
        while len(normalized) < num_seasons:
            normalized.append(0.0)
        return normalized

    def simple_exponential_smoothing(self, alpha, predict_extra=0):
        level = []
        estimate = 0.0
        for t in range(self.n):
            prev = level[-1] if level else estimate
            level.append(prev * (1 - alpha) + self.y[t] * alpha)
        result = list(level)
        for t in range(self.n, self.n + predict_extra):
            result.append(level[self.n - 1])

        return self.__class__(result)

    def simple_seasonal_exponential_smoothing(self, alpha, gamma, seasons, predict_extra=0):
        result = []
        level = []
        seasonal = []
        estimate = 0.0
        seasonal_estimate = 0.0
        for t in range(self.n):
            prev = level[-1] if t >= 1 else estimate
            seasonal_prev = seasonal[-seasons] if t >= seasons else seasonal_estimate
            level.append(alpha * (self.y[t] - seasonal_prev) + (1 - alpha) * prev)
            seasonal.append(gamma * (self.y[t] - prev) + (1 - gamma) * seasonal_prev)
            result.append(level[t] + seasonal[t])
        for h in range(1, predict_extra + 1):
            t = self.n - 1
            k = (h - 1) // seasons
            result.append(level[t] + seasonal[t + h - seasons * (k + 1)])
        return self.__class__(result)

    def batch(self, k):
        num_buckets = (self.n + k - 1) // k
        y = [mean(self.y[j] for j in range(k * i, min(self.n, k * (i + 1)))) for i in range(num_buckets)]
        x = [min(self.x[j] for j in range(k * i, min(self.n, k * (i + 1)))) for i in range(num_buckets)]
        return self.__class__(y, x)

    def expand_batched(self, k, n, xdiff):
        y = [self.y[i // k] for i in range(n)]
        x = [self.x[0] + xdiff * i for i in range(n)]
        return self.__class__(y, x)


HOUR = 1
DAY = 24 * HOUR
WEEK = 7 * DAY
MONTH = 30 * DAY
YEAR = 365 * DAY


def predict(original, m):
    """
    diffed = original.diff(1)
    xdiff = diffed.x[1] - diffed.x[0]
    batched = diffed.batch(MONTH)

    month_in_year_average = batched.seasonal_average(12)
    month_seasonality = TimeSeries([month_in_year_average[i % 12] for i in range(batched.n)])
    month_seasonality = month_seasonality.expand_batched(MONTH, diffed.n, xdiff)

    deseasonal = diffed - month_seasonality

    hour_in_day_average = deseasonal.seasonal_average(DAY)
    day_seasonality = TimeSeries([hour_in_day_average[i % DAY] for i in range(diffed.n)])

    residual = diffed - month_seasonality - day_seasonality
    print(residual)
    ma = residual.integrate(1, [original.y[0]]).moving_average(0.11)
    print(ma)
    """

    best = float("inf")
    alpha = random.uniform(0.1, 0.1)
    gamma = random.uniform(0.1, 0.1)
    for _ in range(50):
        alpha = min(1, max(0, random.uniform(alpha - 0.01, alpha + 0.01)))
        gamma = min(1, max(0, random.uniform(gamma - 0.01, gamma + 0.01)))
        ses = original.simple_seasonal_exponential_smoothing(alpha, gamma, DAY, m)
        error = 0.0
        for i in range(original.n):
            error += (ses.y[i] - original.y[i]) ** 2

        error /= original.n

        if error < best:
            best = error

    result = []
    for i in range(original.n, n + m):
        result.append(ses.y[i])
    # print(result)
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
    print(t, int(round(d)) % 360, f, int(round(h)))
