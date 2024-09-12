#!/usr/bin/python3
import string

max_len = 200

def random_name():
    l = random.choice([max_len, random.randint(max_len // 2, max_len)])
    return "".join([random.choice(string.ascii_uppercase + string.ascii_lowercase) for _ in range(l)])

import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "CASECHECK":
    print(1)
    print("abc")

if typ == "CASEMATCH":
    print(8)
    print("ABC")
    print("ABc")
    print("AbC")
    print("Abc")
    print("aBC")
    print("aBc")
    print("abC")
    print("abc")

if typ == "GBFAIL":
    print(14)
    print("ABCDEF")
    print("ABC")
    print("ACCURATE")
    print("CCCORPORATE")
    print("BCCEMAIL")
    print("ABCCCCCC")
    print("ABBA")
    print("BBCUK")
    print("BBBBBBBBB")
    print("ABBBBBBCCC")
    print("AABBAA")
    print("AACCAA")
    print("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA")
    print("AAAAABBBBBCCCCC")

if typ == "GCSHIFT":
    print(9)
    print("ABCDEFI")
    print("ABCDEFII")
    print("ABCDEFIII")
    print("ABCDEFIV")
    print("ABCDEFV")
    print("ABCDEFVI")
    print("BCDEFI")
    print("BCDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDEFI")
    print("BCD")

if typ == "GDSHIFT":
    print(100)
    for i in range(100):
        pref = string.ascii_uppercase
        suf1 = chr(ord('A') + i // 26)
        suf2 = chr(ord('A') + i % 26)
        print(pref + suf1 + suf2)
        
if typ == "GESHIFT":
    print(100)
    for i in range(100):
        pref = "".join([random.choice(["X", "Y"]) for j in range(50)])
        middle = string.ascii_uppercase[:10]
        suf1 = chr(ord('A') + i // 26)
        suf2 = chr(ord('A') + i % 26)
        print(pref + middle + suf1 + suf2)

