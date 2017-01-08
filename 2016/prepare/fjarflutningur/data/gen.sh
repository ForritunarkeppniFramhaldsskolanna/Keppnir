#!/bin/bash

# Set the problem name to generate correct file names
PROBLEMNAME="portaler"

g++ -std=c++0x ../submissions/accepted/portaler.cpp -o sol -O3

# Set this if you want to generate answers.
SOLVER=sol

# 1. Create subdirectories and set them to "min"
#    grading mode.

OUT=secret
rm -rf $OUT
mkdir -p $OUT

echo "grading: custom
grader_flags: all" > $OUT/testdata.yaml

pypy gen.py 1000   1000   random  50 0  >$OUT/1a-1234567.in
pypy gen.py 1000   1000   random  0 1   >$OUT/2a-247.in
pypy gen.py 7000   70000  random  100 2 >$OUT/3a-34567.in # (sorry)
pypy gen.py 7000   70000  random  0 3   >$OUT/4a-47.in
pypy gen.py 50000  70000  random  300 4 >$OUT/5a-567.in # (even more sorry...)
pypy gen.py 50000  70000  random  0 5   >$OUT/7a-7.in

pypy gen.py 1000   1000   path    3 6   >$OUT/1b-1234567.in
pypy gen.py 7000   120000 path    3 7   >$OUT/3b-34.in
pypy gen.py 50000  70000  path    3 8   >$OUT/5b-567.in

pypy gen.py 1000   1000   reverse 3 9   >$OUT/1c-1234567.in
pypy gen.py 7000   120000 reverse 3 10  >$OUT/3c-34.in
pypy gen.py 50000  70000  reverse 3 11  >$OUT/5c-67.in

pypy gen.py 1000   1000   cycle   3 12  >$OUT/1d-1234567.in
pypy gen.py 7000   120000 cycle   3 13  >$OUT/3d-34.in
pypy gen.py 50000  70000  cycle   3 14  >$OUT/5d-67.in

pypy gen.py 7000   120000 path2   0 15  >$OUT/3e-34.in

# generate solutions for all files
if [[ ! -z $SOLVER ]]
then
    for f in secret/*.in
    do
        echo "solving $f"
        ./$SOLVER < $f > ${f%???}.ans
    done
fi
