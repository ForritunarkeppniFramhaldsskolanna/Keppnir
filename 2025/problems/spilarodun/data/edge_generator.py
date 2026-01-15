#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "fourkeys1":
    print(2)
    print("never forget, 00000000, Annad, 2001-09-11")
    print("never forget, 00000001, Annad, 2001-09-11")
    print("dagsetning flokkur nafn id")

if typ == "fourkeys2":
    print(2)
    print("never forget, 00000001, Annad, 2001-09-11")
    print("never forget, 00000000, Annad, 2001-09-11")
    print("dagsetning flokkur nafn id")
