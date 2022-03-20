#!/usr/bin/python3
import sys

p1,p3 = sys.stdin.readline().split('|')
p2,p4 = sys.stdin.readline().split('|')

sys.stdout.write(f"{p1.rstrip()}{p2.rstrip()} {p3.rstrip()}{p4.rstrip()}\n")
