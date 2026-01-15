_ = input()
a, b, t = map(int, input().strip().split())
days = b - a + 1
wrk = (t + days - 1) // days
print(wrk)
