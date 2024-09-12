#!/usr/bin/python3
mappings = {}
mappings['dvorak on qwerty'] = {'~': '~', '1': '1', '2': '2', '3': '3', '4': '4', '5': '5', '6': '6', '7': '7', '8': '8', '9': '9', '0': '0', '[': '-', ']': '=', "'": 'q', ',': 'w', '.': 'e', 'p': 'r', 'y': 't', 'f': 'y', 'g': 'u', 'c': 'i', 'r': 'o', 'l': 'p', '/': '[', '=': ']', 'a': 'a', 'o': 's', 'e': 'd', 'u': 'f', 'i': 'g', 'd': 'h', 'h': 'j', 't': 'k', 'n': 'l', 's': ';', '-': "'", ';': 'z', 'q': 'x', 'j': 'c', 'k': 'v', 'x': 'b', 'b': 'n', 'm': 'm', 'w': ',', 'v': '.', 'z': '/', ' ': ' '}
mappings['bjarki on dvorak'] = {'0': '~', '2': '1', '4': '2', '8': '3', '6': '4', '1': '5', '3': '6', '5': '7', '7': '8', '9': '9', '=': '0', '-': '[', '/': ']', 'b': "'", 'j': ',', 'a': '.', 'r': 'p', 'k': 'y', 'i': 'f', 'g': 'g', 'u': 'c', 's': 'r', 't': 'l', '.': '/', ',': '=', 'l': 'a', 'o': 'o', 'e': 'e', 'm': 'u', 'p': 'i', 'd': 'd', 'c': 'h', 'n': 't', 'v': 'n', 'q': 's', ';': '-', '[': ';', ']': 'q', 'y': 'j', 'z': 'k', 'h': 'x', 'w': 'b', 'f': 'm', 'x': 'w', "'": 'v', '~': 'z', ' ': ' '}
case = input()
line = input()
for c in line:
    print(mappings[case][c], end='')
print()
