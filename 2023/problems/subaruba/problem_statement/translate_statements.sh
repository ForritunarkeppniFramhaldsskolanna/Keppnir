#!/bin/bash

for lang in {is,en}; do
    original="original.$lang.tex"
    lines=$(wc -l < $original)
    file="problem.$lang.tex"
    echo "D" >> temp
    echo "$lines" >> temp
    cat "$original" >> temp
    pypy3 ../submissions/accepted/arnar_100.py statement < temp > "$file"
    rm temp
done;
    
