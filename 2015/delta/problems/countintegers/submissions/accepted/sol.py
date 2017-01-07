n = int(raw_input())
x, y = map(int, raw_input().split())

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b

print(n // x + n // y - n // lcm(x, y))

