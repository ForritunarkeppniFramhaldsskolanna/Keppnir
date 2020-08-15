import sys

def is_leap(y):
    if y % 4 == 0:
        if y % 100 == 0:
            if y % 400 == 0:
                return True
            return False
        return True
    return False


year = int(sys.stdin.readline().strip())

cnt = 0
for y in range(2021, year+1):
    if is_leap(y):
        cnt += 1

if is_leap(year):
    print(cnt)
else:
    print('Neibb')

