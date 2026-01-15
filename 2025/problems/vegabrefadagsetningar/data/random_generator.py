#!/usr/bin/python3
import datetime
import sys
import random

random.seed(int(sys.argv[-1]))

min_year = int(sys.argv[1])
max_year = int(sys.argv[2])

assert min_year >= 2025 - 10
assert max_year <= 2025 + 10

date = None
while not date:
    try:
        day = random.randint(1, 31)
        month = random.randint(1, 12)
        year = random.randint(min_year, max_year)
        date = datetime.date(year, month, day)
    except ValueError:
        pass

months_en = ["JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"]
months_is = ["JAN", "FEB", "MAR", "APR", "MAÍ", "JÚN", "JÚL", "ÁGÚ", "SEP", "OKT", "NÓV", "DES"]

month_en = months_en[date.month - 1]
month_is = months_is[date.month - 1]
year = date.year % 100

# 13 ÁGÚ /AUG 25
sys.stdout.write(f"{date.day:02} {month_is} /{month_en} {year}\n")
