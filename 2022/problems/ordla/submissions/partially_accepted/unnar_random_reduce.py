#!/usr/bin/python3
import random
import string
from collections import defaultdict

n = int(input())
words = set()

for i in range(n):
    words.add(input())
guess = random.choice(list(words))
words.remove(guess)
print(guess, flush=True)
result = input()
while result != 'OOOOO':
    cnt = defaultdict(int)
    cnt2 = defaultdict(int)
    for i, c in enumerate(result):
        tmp_words = set()
        for w in words:
            if c == 'O' and w[i] != guess[i]:
                pass
            elif c == 'X' and w[i] == guess[i]:
                pass
            elif c == '/' and not w.contains(guess[i]):
                pass
            else:
                tmp_words.add(w)
        words = tmp_words
        if c != 'X':
            cnt[guess[i]] += 1
        else:
            cnt2[guess[i]] += 1
    tmp_words = set()
    for w in words:
        tmp = defaultdict(int)
        for c in w:
            tmp[c] += 1 
        for c in string.ascii_lowercase:
            if tmp[c] < cnt[c]:
                pass
            elif tmp[c]-cnt[c] > 0 and cnt2[c] > 0:
                pass
            else:
                tmp_words.add(w)
    words = tmp_words
    guess = random.choice(list(words))
    words.remove(guess)
    print(guess, flush=True)
    result = input()                
