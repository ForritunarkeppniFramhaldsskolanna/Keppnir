#!/usr/bin/python3
import sys

ip = sys.stdin.readline().rstrip().split(":")

ip = "".join([g.rjust(4,'0') for g in ip])

sys.stdout.write(".".join(list(ip)[::-1])+".ip6.arpa.\n")



