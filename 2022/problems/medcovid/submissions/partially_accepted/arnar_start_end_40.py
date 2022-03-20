#!/usr/bin/python3
dna = input()
if dna[:3] == "COV" or dna[-3:] == "COV":
    print("Veikur!")
else:
    print("Ekki veikur!")
