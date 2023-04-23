#!/bin/python3
p, w = map(int, input().split())
bar = ""
for i in range(p*w//100):
    bar = bar + "#"
for i in range(w - p*w//100):
    bar = bar + "-"
print("[{}] | {:>3}%".format(bar, p))
