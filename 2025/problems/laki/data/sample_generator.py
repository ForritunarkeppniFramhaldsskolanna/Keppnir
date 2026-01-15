#!/usr/bin/python3
import sys

group = sys.argv[1]

cases = {
    "A": "123 + 456",
    "B": '"abc0123" + "ABCDEF"',
    "C": "0x123 + 0xabc",
    "D": "7 + 2i + 11 + 9i",
    "E": "log(5) + log(4)",
    "F": "{0, 1, 4, 9} + {0, 2, 4, 6, 8}",
    "G": "H + H",
    "H": "𝋱 + 𝋳",
    "I": "3 mod 11 + 2 mod 3",
}

print(cases[group])
