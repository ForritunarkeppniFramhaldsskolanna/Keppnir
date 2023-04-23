#!/usr/bin/env python3

INF = 12 * 10**8

steps = []
steps.append((409986, 31.45))
steps.append((1151012, 37.95))
steps.append((INF, 46.25))

l = float(input())
s = float(input())

salary = []
for i in range(12):
    salary.append(int(input()))

d = 59665

discount_left, ans = 0, 0
for amount in salary:
    discount_left += d

    pension = int(amount * l / 100)
    saving = int(amount * s / 100)
    tax_base = amount - pension - saving

    withholding = 0.0
    left, last_threshold = tax_base, 0
    for a, p in steps:
        if left <= 0:
            break
        in_bracket = min(left, a - last_threshold)
        withholding += in_bracket * p / 100
        left -= in_bracket
        last_threshold = a

    withholding = int(withholding)
    discount_to_use = min(discount_left, withholding)
    discount_left -= discount_to_use
    after_tax = tax_base - withholding + discount_to_use;
    ans += after_tax
print(ans)
