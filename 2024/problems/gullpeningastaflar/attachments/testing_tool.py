#!/usr/bin/python3
#
# Testing tool for the Gullpeningastaflar problem.
#
# Usage:
#
#   python3 testing_tool.py [-f input_file] <program>
#
# If the -f parameter is not specified, a random sample with n = 10 is used. 
# Otherwise, an input file is needed. The file should contain n, k on the first
# line, where k is the location of the real coins. For example:
#
# 10 4
#
# You can compile and run your solution as follows.
# - You may have to replace 'python3' by just 'python'.
# - On Windows, you may have to to replace '/' by '\'.

# C++:
#   g++ solution.cpp
#   python3 testing_tool.py ./a.out

# Java
#   javac solution.java
#   python3 testing_tool.py java solution

# Python3
#   python3 testing_tool.py python3 ./solution.py

# The tool is provided as-is, and you should feel free to make
# whatever alterations or augmentations you like to it.
#
# The tool attempts to detect and report common errors, but it
# is not guaranteed that a program that passes the testing tool
# will be accepted.
#

import argparse
import subprocess
import sys
import traceback
import string
import random

def write(p, line):
    assert p.poll() is None, 'Program terminated early'
    print('Write: {}'.format(line), flush=True)
    p.stdin.write('{}\n'.format(line))
    p.stdin.flush()


def read(p):
    assert p.poll() is None, 'Program terminated early'
    line = p.stdout.readline().strip()
    assert line != '', 'Read empty line or closed output pipe. Make sure that your program started successfully.'
    print('Read: %s' % line, flush=True)
    return line


parser = argparse.ArgumentParser(description='Testing tool for gullpeningastaflar')
parser.add_argument('-f', dest='inputfile', metavar='inputfile', default=None, type=argparse.FileType('r'),
                    help='Custom input file (defaults to random)')
parser.add_argument('program', nargs='+', help='Your solution')

args = parser.parse_args()
n, k = 10, random.randint(1, 10)

if args.inputfile is not None:
    # Read the input file
    with args.inputfile as f:
        n, k = map(int, f.readline().strip().split())
        assert 1 <= n <= 1024, 'n must be a positive integer that is at most 1024'
        if n != 1024:
            print('Warning: n is not equal to 1024')
        assert 1 <= k <= n, "k must be betweeen 1 and n, inclusive"
        assert f.readline() == '', 'Extra data at end of input file'

with subprocess.Popen(" ".join(args.program), shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
                          universal_newlines=True) as p:
    try:
        write(p, f"{n}")
        query_count = 0
        while True:
            query = read(p).strip().split()
            operation = query.pop(0)
            assert operation in "?!", f"Expected operation to be ? or ! but got {operation}"
            is_final_answer = operation == '!'
            if is_final_answer:
                assert len(query) == 1, 'Too many values in final answer'
                final_answer = int(query[0])
                assert 1 <= final_answer <= n, f'Final answer must be between 1 and {n}, got {final_answer}'
                assert final_answer == k, f'Final answer incorrect. Expected {k}, but got {final_answer}'
                break
            else:
                assert query_count < 2*n, f'Exceeded max queries'
                query_count += 1
                assert len(query) == n, f'Query is not of length {n}, actual length is {len(query)}'
                query = list(map(int, query))
                sm = 0
                for j in range(n):
                    assert 0 <= query[j] <= n, f'Query value {query[j]} at index {j} is out of bounds'
                    sm += query[j] * (n+1) if j + 1 == k else query[j] * n
                
                write(p, f'{sm}')
        assert p.stdout.readline() == '', 'Printed extra data after finding answer'
        assert p.wait() == 0, 'Did not exit cleanly after finishing'
        sys.stdout.flush()
        sys.stderr.flush()
        sys.stdout.write(f'Solved case correctly in {query_count} queries.\n')
        sys.stdout.flush()
    except:
        write(p, "0")
        p.kill()
        traceback.print_exc()
