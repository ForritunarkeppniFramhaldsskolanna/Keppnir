#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
test_type = sys.argv[2]

n = random.randint(1, max_n)
if test_type == 'random':
    L = [str(random.randint(0,1)) for i in range(n)]
    print(''.join(L))

if test_type == 'all_ones':
    s = '1'*max_n
    print(s)

if test_type == 'all_zeros':
    s = '0'*max_n
    print(s)

if test_type == 'zero_one_r':
    s = '01' * (max_n // 2)
    print(s)

if test_type == 'one_zero_r':
    s = '10' * (max_n // 2)
    print(s)

if test_type == 'zero_one':
    s = '0' * (max_n // 2) + '1' * (max_n // 2)
    print(s)

if test_type == 'one_zero':
    s = '1' * (max_n // 2) + '0' * (max_n // 2)
    print(s)

if test_type == 'one_zero_one':
    t = max_n // 3
    s = '1' * t + '0' * t + '1' * t
    print(s)

if test_type == 'zero_one_zero':
    t = max_n // 3
    s = '0' * t + '1' * t + '0' * t
    print(s)

if test_type == 'zero_one_zero_one':
    q = max_n // 4
    s = ('0' * q + '1' * q) * 2
    print(s)

if test_type == 'one_zero_one_zero':
    q = max_n // 4
    s = ('1' * q + '0' * q) * 2
    print(s)

if test_type.startswith('test'):
    with open(test_type[5:]+'.txt', 'r') as f:
        line = f.readline()
        print(line.strip())
