#!/bin/python3
n = int(input())
words = input().split()
print(''.join(word[0] for word in words))
