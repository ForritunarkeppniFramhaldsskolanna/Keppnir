#!/usr/bin/python3
import sys

p1,p3 = sys.stdin.readline().rstrip().split('|')
p2,p4 = sys.stdin.readline().rstrip().split('|')

sys.stdout.write(f"{p1}{p2} {p3}{p4}\n")
