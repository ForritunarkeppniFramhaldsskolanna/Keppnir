import datetime

months = ["", "JAN", "FEB", "MAR", "APR", "MAÍ", "JÚN", "JÚL", "ÁGÚ", "SEP", "OKT", "NÓV", "DES"]
day, month, _, year = [i for i in input().split(" ")]

print(datetime.date(2000 + int(year), months.index(month), int(day)))
