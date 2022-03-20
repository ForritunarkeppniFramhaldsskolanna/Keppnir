#!/bin/bash
s=1
while [ 1 ]
do 
    python ../../data/random_generator.py 8 rand "$s" > tmp.in
    if [[ $(diff <(./corr < tmp.in) <(./wrng < tmp.in)) ]];
    then
        break
    fi
    ((s++))
done
