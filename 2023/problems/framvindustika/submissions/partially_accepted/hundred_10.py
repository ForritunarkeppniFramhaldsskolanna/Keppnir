#!/bin/python3
p, w = map(int, input().split())
hashtags = p
dashes = w - hashtags
print("[{}{}] | {:>3}%".format("#"*hashtags, "-"*dashes, p))
