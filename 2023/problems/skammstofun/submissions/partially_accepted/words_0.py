#!/bin/python3
n = int(input())
words = input().split()
print(''.join(word for word in words if word[0].isupper()))
