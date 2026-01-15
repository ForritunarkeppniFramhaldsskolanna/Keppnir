from random import randint
from random import uniform

n, m = map(int, input().split())
for i in range(m):
    temperature = uniform(-50.0, 50.0)
    direction = randint(0, 359)
    force = uniform(0.0, 80.0)
    humidity = randint(0, 100)
    print(f"{temperature} {direction} {force} {humidity}")
