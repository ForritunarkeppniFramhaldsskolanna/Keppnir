#!/usr/bin/python3
import datetime
import sys
import random

random.seed(int(sys.argv[-1]))

year = int(sys.argv[1])
month = int(sys.argv[2])
day = int(sys.argv[3])

date = datetime.date(year, month, day)
assert date

months_en = ["JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"]
months_is = ["JAN", "FEB", "MAR", "APR", "MAÍ", "JÚN", "JÚL", "ÁGÚ", "SEP", "OKT", "NÓV", "DES"]

month_en = months_en[date.month - 1]
month_is = months_is[date.month - 1]
year = date.year % 100

# 13 ÁGÚ /AUG 25
sys.stdout.write(f"{date.day:02} {month_is} /{month_en} {year}\n")
