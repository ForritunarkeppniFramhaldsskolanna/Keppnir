#!/usr/bin/python3
import sys

KEY = "ub"

def decrypt(s):
    return s.replace(KEY, '')

mode = sys.stdin.readline().strip()
n = int(sys.stdin.readline())
lines = sys.stdin.read()

print(decrypt(lines))
