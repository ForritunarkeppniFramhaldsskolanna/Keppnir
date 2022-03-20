#!/usr/bin/python3
import sys
import random

cat_list = [
    ("Logn", (0, 0.2)),
    ("Andvari", (0.3, 1.5)),
    ("Kul", (1.6, 3.3)),
    ("Gola", (3.4, 5.4)),
    ("Stinningsgola", (5.5, 7.9)),
    ("Kaldi", (8.0, 10.7)),
    ("Stinningskaldi", (10.8, 13.8)),
    ("Allhvass vindur", (13.9, 17.1)),
    ("Hvassvidri", (17.2, 20.7)),
    ("Stormur", (20.8, 24.4)),
    ("Rok", (24.5, 28.4)),
    ("Ofsavedur", (28.5, 32.6)),
    ("Farvidri", (32.7, 200.0)),
]

random.seed(int(sys.argv[-1]))
for i in range(1):
    random.randint(1, 2)

max_k = float(sys.argv[1])
category = int(sys.argv[2])
test_type = sys.argv[3]

cat_name, (cat_start, cat_stop) = cat_list[category]
gen_start = 10 * cat_start + 1
gen_stop = 10 * min([cat_stop, max_k]) - 1
random_wind_measurement_in_category = (
    random.randint(gen_start, gen_stop) / 10
)
if test_type == "low":
    random_wind_measurement_in_category = cat_start
elif test_type == "high":
    random_wind_measurement_in_category = cat_stop
print("{:.1f}".format(round(random_wind_measurement_in_category, 1)))
