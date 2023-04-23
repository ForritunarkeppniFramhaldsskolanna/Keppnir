#!/bin/python3
p, w = map(int, input().split())
hashtags = p*w//100
dashes = w - hashtags
print("[{}{}] | {:>3}%".format("#"*hashtags, "-"*dashes, p))
