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
        return str(self.y)

    def seasonal_average(self, num_seasons):
        unnormalized_seasonal_average = [
            mean(self.y[j] for j in range(i, self.n, num_seasons)) for i in range(num_seasons)
        ]
        average = mean(unnormalized_seasonal_average)
        return [x - average for x in unnormalized_seasonal_average]


temperature = []
direction = []
force = []
humidity = []

for i in range(n):
    try:
        a, b, c, d = map(float, input().split())
    except Exception:
        continue
    temperature.append(a)
    direction.append(b)
    force.append(c)
    humidity.append(d)

temperature = TimeSeries(temperature)

trend = temperature.trend()
detrended = temperature.detrended()

HOURS_IN_DAY = 24
hour_in_day_average = detrended.seasonal_average(HOURS_IN_DAY)
daily_seasonality = TimeSeries([hour_in_day_average[i % HOURS_IN_DAY] for i in range(n)])
remaining = detrended - daily_seasonality

slope = trend.diff().y[0]
intercept = trend.y[0] - m * trend.x[0]

for i in range(n, n + m):
    trend_prediction = slope * i + intercept
    daily_seasonality_prediction = daily_seasonality.y[i % HOURS_IN_DAY]
    print(trend_prediction, "-", "-", "-")
