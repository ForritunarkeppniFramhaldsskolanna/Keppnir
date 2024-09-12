#!/usr/bin/python3
import sys
import random

from ipaddress import IPv4Address, IPv6Address
from string import ascii_letters

charset = ascii_letters + "_-"

DEFINE = '+'
UNDEFINE = '-'
SET = '='
GET = '?'

MIN_IPV4 = int(IPv4Address("0.0.0.0"))
MAX_IPV4 = int(IPv4Address("255.255.255.255"))
MIN_IPV6 = int(IPv6Address("::"))
MAX_IPV6 = int(IPv6Address("ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff"))
IPV4_IN_IPV6_BASE = int(IPv6Address("::ffff:0:0"))
MIN_IPV4_AS_IPV6 = IPV4_IN_IPV6_BASE + MIN_IPV4
MAX_IPV4_AS_IPV6 = IPV4_IN_IPV6_BASE + MAX_IPV4

random.seed(int(sys.argv[-1]))

min_q = int(sys.argv[1])
max_q = int(sys.argv[2])
min_ip = sys.argv[3]
max_ip = sys.argv[4]
gen_type = sys.argv[5]

assert gen_type in ["all", "define_get", "edge_whole_range"]

ipv4_only = not (":" in min_ip or ":" in max_ip)

min_ipv4 = (int(IPv4Address(min_ip)) if ipv4_only else
            max(int(IPv6Address(min_ip)) - IPV4_IN_IPV6_BASE, MIN_IPV4))
max_ipv4 = (int(IPv4Address(max_ip)) if ipv4_only else
            min(int(IPv6Address(max_ip)) - IPV4_IN_IPV6_BASE, MAX_IPV4))
min_ipv6 = (None if ipv4_only else
            int(IPv6Address(min_ip)))
max_ipv6 = (None if ipv4_only else
            int(IPv6Address(max_ip)))

ip_type_weights = [1, 0, 0, 0] if ipv4_only else [1, 1, 1, 1]

sys.stderr.write(f"{min_ipv4}\n")
sys.stderr.write(f"{max_ipv4}\n")
sys.stderr.write(f"{min_ipv6}\n")
sys.stderr.write(f"{max_ipv6}\n")

def gen_ipv4_address():
    return IPv4Address(random.randint(min_ipv4, max_ipv4))

def gen_ipv4_as_ipv6_address():
    if min_ipv6 > MAX_IPV4_AS_IPV6:
        return None
    if max_ipv6 < MIN_IPV4_AS_IPV6:
        return None
    mn = max(MIN_IPV4_AS_IPV6, min_ipv6)
    mx = min(MAX_IPV4_AS_IPV6, max_ipv6)
    return IPv6Address(random.randint(mn, mx))

def gen_ipv6_address():
    if min_ipv6 is None or max_ipv6 is None:
        return None
    return IPv6Address(random.randint(min_ipv6, max_ipv6))

def gen_shortened_ipv6_address():
    ip = gen_ipv6_address()
    if ip is None:
        return None
    bit_count = max_ipv6.bit_length()
    middle_bit_count = random.randint(1, bit_count)
    middle_bit_pos = random.randint(0, bit_count - middle_bit_count)
    prefix_ones = middle_bit_pos
    suffix_ones = bit_count - prefix_ones - middle_bit_count
    mask = 2 ** bit_count - 1 # 1...1
    mask -= 2 ** (suffix_ones + middle_bit_count) - 1 # 1...10...0#
    mask += 2 ** suffix_ones - 1 # 1...10...01...1
    return IPv6Address(mask & int(ip))

def get_ip_gen():
    funcs = [gen_ipv4_address, gen_ipv6_address, gen_ipv4_as_ipv6_address, gen_shortened_ipv6_address]
    return random.choices(funcs, weights=ip_type_weights, k=1)[0]

def gen_ip_range():
    ip_gen = get_ip_gen()
    start_ip = ip_gen()
    end_ip = ip_gen()
    if start_ip > end_ip:
        start_ip, end_ip = end_ip, start_ip
    return start_ip, end_ip

def gen_ip_address():
    return get_ip_gen()()

defined_keys = []
undefined_keys = []
line_count = 0
max_defs = 100000
max_lines = 300000

def gen_existing_key():
    global defined_keys
    if len(defined_keys) == 0:
        return None
    return random.choice(defined_keys)

def gen_value():
    sz = random.randint(1, 10)
    return "".join(random.choices(charset, k=sz))

def gen_define():
    global defined_keys
    if len(defined_keys) == max_defs:
        return None
    sz = random.randint(1, 10)
    key = "".join(random.choices(charset, k=sz))
    if len(undefined_keys) > 0 and random.randint(1,100) == 1:
        key = random.choice(undefined_keys)
    if key in undefined_keys:
        undefined_keys.remove(key)
    if key not in defined_keys:
        defined_keys.append(key)
    value = gen_value()
    return f"{DEFINE} {key} {value}"

def gen_undefine():
    global defined_keys
    key = gen_existing_key()
    if key is None:
        return None
    defined_keys.remove(key)
    if key not in undefined_keys:
        undefined_keys.append(key)
    return f"{UNDEFINE} {key}"
    
def gen_set():
    start_ip, end_ip = gen_ip_range()
    key = gen_existing_key()
    value = gen_value()
    if any(x is None for x in (key, value, start_ip, end_ip)):
        return None
    return f"{SET} {start_ip} {end_ip} {key} {value}"

def gen_get():
    global defined_keys, line_count
    new_line_count = line_count + len(defined_keys)
    if new_line_count > max_lines:
        return None
    line_count = new_line_count
    return f"{GET} {gen_ip_address()}"

q = random.randint(min_q, max_q)

op_weights = [random.uniform(0.01, 1) for _ in range(4)]
op_options = [DEFINE, UNDEFINE, SET, GET]
generators = {DEFINE: gen_define, UNDEFINE: gen_undefine, SET: gen_set, GET: gen_get}

def gen_all():
    print(q)
    for _ in range(q):
        op = None
        while op is None:
            cur_op_type = random.choices(op_options, op_weights, k=1)[0]
            op = generators[cur_op_type]()
        print(op)

def gen_define_get():
    num_defines = int(sys.argv[6])
    assert num_defines <= q
    num_gets = q - num_defines
    print(q)
    for _ in range(num_defines):
        op = None
        while op is None:
            op = gen_define()
        print(op)
    for _ in range(num_gets):
        op = None
        while op is None:
            op = gen_get()
        print(op)

def gen_edge_whole_range():
    print(q)
    print("+ k v1")
    if ipv4_only:
        print(f"= {IPv4Address(MIN_IPV4)} {IPv4Address(MAX_IPV4)} k v2")
    else:
        print(f"= {IPv6Address(MIN_IPV6)} {IPv6Address(MAX_IPV6)} k v2")
    print("+ k v3")
    for _ in range(3, q):
        print(gen_get())

if __name__ == "__main__":
    if gen_type == "all":
        gen_all()
    elif gen_type == "define_get":
        gen_define_get()
    elif gen_type == "edge_whole_range":
        gen_edge_whole_range()
    else:
        assert False, "Unreachable"
