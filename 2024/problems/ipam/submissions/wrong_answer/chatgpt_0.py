#!/usr/bin/python3
from ipaddress import ip_address

# Data structures for property definitions and IP address properties
property_defaults = {}
ip_properties = {}

# Function to convert IP address to a uniform format for easy handling
def convert_ip(ip):
    return int(ip_address(ip))

# Operation functions
def define_property(name, value):
    property_defaults[name] = value

def remove_property(name):
    del property_defaults[name]
    for ip in ip_properties:
        if name in ip_properties[ip]:
            del ip_properties[ip][name]

def set_property(start_ip, end_ip, name, value):
    start = convert_ip(start_ip)
    end = convert_ip(end_ip)
    for ip_int in range(start, end + 1):
        ip_str = str(ip_address(ip_int))
        if ip_str not in ip_properties:
            ip_properties[ip_str] = {}
        ip_properties[ip_str][name] = value

def get_properties(ip):
    properties = ip_properties.get(ip, {})
    # Add default values if not overridden
    for name, value in property_defaults.items():
        properties.setdefault(name, value)
    return properties

# Main program to process commands
def main():
    q = int(input().strip())
    for _ in range(q):
        operation = input().strip().split()
        cmd = operation[0]
        if cmd == "+":
            define_property(operation[1], operation[2])
        elif cmd == "-":
            remove_property(operation[1])
        elif cmd == "=":
            set_property(operation[1], operation[2], operation[3], operation[4])
        elif cmd == "?":
            ip = operation[1]
            properties = get_properties(ip)
            sorted_properties = sorted(properties.items())
            print(len(sorted_properties))
            for name, value in sorted_properties:
                print(name, value)

if __name__ == "__main__":
    main()

