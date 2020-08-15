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

if not is_leap(year):
    print('Neibb')
    sys.exit(0)

def count(y):
    return y//4 - y//100 + y//400

print(count(year) - count(2020))

