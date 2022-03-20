#!/usr/bin/python3
import sys

ip = sys.stdin.readline().rstrip()

if ":" in ip:
    if "::" in ip:
        ip = ip.split("::")
        groups = len(ip[0].split(":") + ip[1].split(":"))
        if "" in ip: groups -= 1
        ip = ip[0].split(":") + ['0' for i in range(8-groups)] + ip[1].split(":")
        if "" in ip: ip.remove("")
    else:
        ip = ip.split(":")
    
    ip = "".join([g.rjust(4,'0') for g in ip])

    sys.stdout.write(".".join(list(ip)[::-1])+".ip6.arpa.\n")
else:
    sys.stdout.write('.'.join(ip.split('.')[::-1]) + ".in-addr.arpa.\n")
