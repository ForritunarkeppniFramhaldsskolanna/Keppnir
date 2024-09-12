#!/usr/bin/python3
import ipaddress


class IPAddress:
    def __init__(self, address):
        try:
            self.ip = ipaddress.ip_address(address)
        except ValueError:
            raise ValueError("Invalid IP address format")

    def __str__(self):
        return str(self.ip)

    def __ge__(self, other):
        return self.ip >= other.ip  # For range comparisons if needed

    def __gt__(self, other):
        return self.ip > other.ip  # For range comparisons if needed

    def __le__(self, other):
        return self.ip <= other.ip  # For range comparisons if needed

    def __lt__(self, other):
        return self.ip < other.ip  # For range comparisons if needed

    def __eq__(self, other):
        return self.ip == other.ip


def process_ip_range(start_ip, end_ip):
    current_ip = start_ip
    while current_ip <= end_ip:
        # Process the current_ip address
        yield current_ip  # Consider yielding for flexibility
        current_ip += 1  # Increment to the next IP


ip_properties = {}
property_definitions = {}


def process_operation(line):
    op, *args = line.split()

    if op == "+":  # Define property
        property_definitions[args[0]] = args[1]  # Store default value

    elif op == "-":  # Remove property
        del property_definitions[args[0]]
        for ip_addr in ip_properties:
            if args[0] in ip_properties[ip_addr]:
                del ip_properties[ip_addr][args[0]]

    elif op == "=":  # Set property
        start_ip = IPAddress(args[0])
        end_ip = IPAddress(args[1])
        prop_name = args[2]
        prop_value = args[3]

        print(f"{str(start_ip)=}\t{str(end_ip)=}")
        for ip_addr in process_ip_range(start_ip, end_ip):
            ip_str = str(ip_addr)
            if ip_str not in ip_properties:
                ip_properties[ip_str] = {}
                # Apply default values
                for prop, default_val in property_definitions.items():
                    ip_properties[ip_str][prop] = default_val

            ip_properties[ip_str][prop_name] = prop_value

    elif op == "?":  # Get property
        ip_str = args[0]
        if ip_str in ip_properties:
            props = ip_properties[ip_str]
            print(len(props))
            for prop_name, prop_value in sorted(props.items()):
                print(prop_name, prop_value)
        else:
            print(0)  # No properties found


# Input Handling
num_operations = int(input())
for _ in range(num_operations):
    process_operation(input())
