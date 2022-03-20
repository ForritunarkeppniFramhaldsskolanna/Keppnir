#!/usr/bin/python3
import sys

ip = sys.stdin.readline().rstrip()

if ":" in ip:
    ip = "".join([g.rjust(4,'0') for g in ip.split(":")])
    sys.stdout.write(".".join(list(ip)[::-1]) + ".ip6.arpa.\n")
else:
    sys.stdout.write('.'.join(ip.split('.')[::-1]) + ".in-addr.arpa.\n")
