#!/usr/bin/python3
# read input values
monnei_fee = int(input())
fjee_fee = int(input())
dolladollabilljoll_fee = int(input())

# create a list of fees and find the minimum
fees = [monnei_fee, fjee_fee, dolladollabilljoll_fee]
min_fee = min(fees)

# check which service has the minimum fee and print its name
if min_fee == monnei_fee:
    print("Monnei")
elif min_fee == fjee_fee:
    print("Fjee")
else:
    print("Dolladollabilljoll")

