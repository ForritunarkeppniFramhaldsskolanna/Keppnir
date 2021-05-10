#!/usr/bin/env bash
while [ true ]
do
	inp=$(./gen 100000 100000 100)
	echo $inp > test-file
	out1=$(echo $inp | ./a.out)
	out2=$(echo $inp | ./b.out)
	if [ "$out1" != "$out2" ]
	then
		break
	fi
done
