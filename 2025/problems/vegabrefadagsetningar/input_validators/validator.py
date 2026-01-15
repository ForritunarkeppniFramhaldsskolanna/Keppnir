#!/usr/bin/python3
import datetime
import sys

months_en = ["JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"]
months_is = ["JAN", "FEB", "MAR", "APR", "MAÍ", "JÚN", "JÚL", "ÁGÚ", "SEP", "OKT", "NÓV", "DES"]

line = sys.stdin.readline()
assert len(line) == len("08 MAR /MAR 25\n"), repr(line)

day, month_is, month_en, year = line.split(" ")
assert month_en[0] == "/"
month_en = month_en[1:]

year = int(year)
assert 15 <= year <= 35, repr(year)

assert month_is in months_is
assert month_en in months_en
assert months_is.index(month_is) - months_en.index(month_en) == 0

year = 2000 + year
month = months_is.index(month_is) + 1
day = int(day)

assert datetime.date(year, month, day)

assert not sys.stdin.readline()

exit(42)
