#!/bin/python3
p, w = map(int, input().split())
hashtags = p if w == 100 else p//10
dashes = w - hashtags
print("[{}{}] | {:>3}%".format("#"*hashtags, "-"*dashes, p))
