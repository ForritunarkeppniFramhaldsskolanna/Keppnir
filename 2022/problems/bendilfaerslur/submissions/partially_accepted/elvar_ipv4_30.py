#!/usr/bin/python3
import sys

ip = sys.stdin.readline().rstrip()

sys.stdout.write('.'.join(ip.split('.')[::-1]) + ".in-addr.arpa.\n")

