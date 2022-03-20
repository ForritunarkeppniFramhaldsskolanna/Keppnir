#!/usr/bin/python3
#
# Testing tool for the Pizza String problem.
#
# Usage:
#
#   python3 testing_tool.py [-f input_file] <program>
#
# If the -f parameter is not specified, sample 1 is used. Otherwise,
# an input file is needed. The file should only contain 4 lowercase
# letters. For example:
#
# If the -f parameter is not specified, sample 1 is used. Otherwise,
# an input file is needed. The file should only contain a string consisting
# of the characters 'P', 'I', 'Z', 'A'. For example:
#
# PIZZA

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


parser = argparse.ArgumentParser(description='Testing tool for pizzastrengur')
parser.add_argument('-f', dest='inputfile', metavar='inputfile', default=None, type=argparse.FileType('r'),
                    help='Custom input file (defaults to sample 1)')
parser.add_argument('program', nargs='+', help='Your solution')

args = parser.parse_args()
guesses = 0

if args.inputfile is not None:
    # Read the input file
    with args.inputfile as f:
        password = f.readline().strip()
        assert len(password) <= 10**4
        assert set(password) <= set(['P', 'I', 'Z', 'A']), "Password must only contain characters 'P', 'I', 'Z', 'A'"
        assert f.readline() == '', 'Extra data at end of input file'
else:
    password = 'PIZZA'

with subprocess.Popen(" ".join(args.program), shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
                          universal_newlines=True) as p:
    try:
        write(p, len(password))
        while True:
            guess = read(p).strip()
            assert len(guess) <= len(password), 'Guess is longer than the password'
            guesses += 1

            if guess == password:
                write(p, '2')
                assert p.stdout.readline() == '', 'Printed extra data after finding password'
                assert p.wait() == 0, 'Did not exit cleanly after finishing'
                break
            elif password.startswith(guess):
                write(p, '1')
            else:
                write(p, '0')

            if guesses >= 4 * 10**3:
                sys.stdout.write('Program used too many guesses\n')
                p.kill()
                break
    except:
        traceback.print_exc()
    finally:
        sys.stdout.flush()
        sys.stderr.flush()
        sys.stdout.write('Guessed {} times, exit code: {}\n'.format(guesses, p.wait()))
        sys.stdout.flush()
