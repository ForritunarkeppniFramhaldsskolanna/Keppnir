#!/usr/bin/python3
import ipaddress
print(ipaddress.ip_address(input()).reverse_pointer, end='.\n')
