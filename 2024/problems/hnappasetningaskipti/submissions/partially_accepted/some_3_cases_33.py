#!/usr/bin/python3
mappings = {}
mappings['dvorak on qwerty'] = {'~': '~', '1': '1', '2': '2', '3': '3', '4': '4', '5': '5', '6': '6', '7': '7', '8': '8', '9': '9', '0': '0', '[': '-', ']': '=', "'": 'q', ',': 'w', '.': 'e', 'p': 'r', 'y': 't', 'f': 'y', 'g': 'u', 'c': 'i', 'r': 'o', 'l': 'p', '/': '[', '=': ']', 'a': 'a', 'o': 's', 'e': 'd', 'u': 'f', 'i': 'g', 'd': 'h', 'h': 'j', 't': 'k', 'n': 'l', 's': ';', '-': "'", ';': 'z', 'q': 'x', 'j': 'c', 'k': 'v', 'x': 'b', 'b': 'n', 'm': 'm', 'w': ',', 'v': '.', 'z': '/', ' ': ' '}
mappings['qwerty on bjarki'] = {'~': '0', '1': '2', '2': '4', '3': '8', '4': '6', '5': '1', '6': '3', '7': '5', '8': '7', '9': '9', '0': '=', '-': '-', '=': '/', 'q': 'b', 'w': 'j', 'e': 'a', 'r': 'r', 't': 'k', 'y': 'i', 'u': 'g', 'i': 'u', 'o': 's', 'p': 't', '[': '.', ']': ',', 'a': 'l', 's': 'o', 'd': 'e', 'f': 'm', 'g': 'p', 'h': 'd', 'j': 'c', 'k': 'n', 'l': 'v', ';': 'q', "'": ';', 'z': '[', 'x': ']', 'c': 'y', 'v': 'z', 'b': 'h', 'n': 'w', 'm': 'f', ',': 'x', '.': "'", '/': '~', ' ': ' '}
mappings['dvorak on bjarki'] = {'~': '0', '1': '2', '2': '4', '3': '8', '4': '6', '5': '1', '6': '3', '7': '5', '8': '7', '9': '9', '0': '=', '[': '-', ']': '/', "'": 'b', ',': 'j', '.': 'a', 'p': 'r', 'y': 'k', 'f': 'i', 'g': 'g', 'c': 'u', 'r': 's', 'l': 't', '/': '.', '=': ',', 'a': 'l', 'o': 'o', 'e': 'e', 'u': 'm', 'i': 'p', 'd': 'd', 'h': 'c', 't': 'n', 'n': 'v', 's': 'q', '-': ';', ';': '[', 'q': ']', 'j': 'y', 'k': 'z', 'x': 'h', 'b': 'w', 'm': 'f', 'w': 'x', 'v': "'", 'z': '~', ' ': ' '}
case = input()
line = input()
for c in line:
    print(mappings[case][c], end='')
print()
