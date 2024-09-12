#!/usr/bin/python3
import csv
import random
import tqdm
import sys

from ipaddress import IPv4Address, IPv6Address

DEFINE = 1
UNDEFINE = 2
SET = 3
GET = 4

filename = sys.argv[1]
limit = int(sys.argv[2])
min_q = int(sys.argv[3])
max_q = int(sys.argv[4])
allowed_keys = list(sys.argv[5:-1])
random.seed(int(sys.argv[-1]))

while True:
    defs = []
    set_ops = []

    MIN_IPV4 = int(IPv4Address("0.0.0.0"))
    MAX_IPV4 = int(IPv4Address("255.255.255.255"))

    op_count = random.randint(min_q, max_q)
    lower_bound_int = random.randint(MIN_IPV4, MAX_IPV4)
    upper_bound_int = max(lower_bound_int + 1024,
                          random.randint(lower_bound_int,
                                         min(MAX_IPV4,
                                             lower_bound_int + 1024 * op_count
                                         )
                          )
                      )

    #lower_bound_int = MIN_IPV4
    #upper_bound_int = MAX_IPV4

    lower_bound = IPv4Address(lower_bound_int)
    upper_bound = IPv4Address(upper_bound_int)

    sys.stderr.write(f"{lower_bound} - {upper_bound}\n")

    with open(filename, newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=',', quotechar='"')
        header = None
        for row_index, row in enumerate(reader):
            if row_index >= limit:
                break
            if header:
                start = None
                end = None
                data = {}
                for i, item in enumerate(row):
                    if header[i] == "start":
                        start = IPv4Address(int(item))
                    elif header[i] == "end":
                        end = IPv4Address(int(item))
                    elif header[i] and header[i] in allowed_keys:
                        data[header[i]] = item.replace(' ', '_')
                if lower_bound > end or start > upper_bound:
                    continue
                for key, value in data.items():
                    set_ops.append(f"{SET} {start} {end} {key} {value}")
            else:
                header = list(row)
                for i, item in enumerate(header):
                    if item in allowed_keys:
                        defs.append(f"{DEFINE} {item} -")
    
    if len(set_ops) == 0:
        continue

    ops = list(defs)
    random.shuffle(set_ops)
    assert op_count >= len(defs)
    for i in range(op_count - len(defs)):
        if len(set_ops) > 0 and random.choices([SET, GET], weights=[2*(op_count-i), i], k=1)[0] == SET:
            ops.append(set_ops.pop())
        else:
            ip = IPv4Address(random.randint(lower_bound_int, upper_bound_int))
            ops.append(f"{GET} {ip}")

    print(op_count)
    for op in ops:
        print(op)
    break
