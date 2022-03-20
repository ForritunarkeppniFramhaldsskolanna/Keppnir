#!/usr/bin/python3
import sys
import random
import ipaddress

random.seed(int(sys.argv[-1]))

mode = sys.argv[1]

if mode == "IPV4":
    print(ipaddress.IPv4Address(random.randint(0,2**32-1)))
if mode == "IPV6":
    ip = ":".join(hex(random.randint(1,2**16-1))[2:] for _ in range(8))
    print(ip)
if mode == "IPV6_edge_at":
    shift = (int(sys.argv[2])-1) * 16
    ip = 0
    ip += random.randint(1,2**16-1) << shift
    ip %= 2**128
    print(ipaddress.IPv6Address(ip))
if mode == "IPV6_edge":
    ip = 0
    for i in range(random.randint(1,3)):
        shift = random.randint(0,8) * 16
        ip += random.randint(1,2**16-1) << shift
    ip %= 2**128
    print(ipaddress.IPv6Address(ip))


