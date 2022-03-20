#!/usr/bin/env python3
import random
import string

random.seed(1337)

with open('words.txt', 'r') as f:
    words = f.read().strip().split('\n')

testcase_index = 1
def testcase(words):
    global testcase_index
    words = list(words)
    random.shuffle(words)
    with open('secret/%02d.in' % testcase_index, 'w') as f:
        f.write('%d\n' % len(words))
        for word in words:
            f.write('%s\n' % word)
    with open('secret/%02d.ans' % testcase_index, 'w') as f:
        f.write('\n')
    testcase_index += 1

def strings(n, alpha):
    words = []
    for i in range(min(n, len(alpha)**5)):
        cur = i
        word = ''
        for j in range(5):
            word += alpha[cur % len(alpha)]
            cur = cur // len(alpha)
        words.append(word)
    return words

def random_strings(n, alpha):
    words = set()
    while len(words) < min(n, len(alpha)**5):
        word = ''
        for i in range(5):
            word += random.choice(alpha)
        words.add(word)
    return list(words)

# n <= 10 (30%)

for _ in range(10):
    random.shuffle(words)
    testcase(words[:10])
testcase(sorted(words)[:10])
testcase(sorted(words)[-10:])
testcase(strings(10, 'ab'))
testcase(strings(10, 'xyz'))
testcase(strings(10, 'pqrs'))
testcase(strings(10, 'coeui'))
testcase(strings(10, string.ascii_lowercase))
testcase(random_strings(10, 'ab'))
testcase(random_strings(10, 'xyz'))
testcase(random_strings(10, 'pqrs'))
for _ in range(10):
    testcase(random_strings(10, string.ascii_lowercase))

assert testcase_index <= 31

# n <= 100 (50%)

for l in range(20, 100, 21):
    random.shuffle(words)
    testcase(words[:l])
for _ in range(6):
    random.shuffle(words)
    testcase(words[:100])
for l in [25, 60, 100]:
    testcase(sorted(words)[:l])
    testcase(sorted(words)[-l:])
    testcase(strings(l, 'ab'))
    testcase(strings(l, 'xyz'))
    testcase(strings(l, 'pqrs'))
    testcase(strings(l, 'coeui'))
    testcase(strings(l, string.ascii_lowercase))
    testcase(random_strings(l, 'ab'))
    testcase(random_strings(l, 'xyz'))
    testcase(random_strings(l, 'pqrs'))
for l in range(20, 100, 21):
    testcase(random_strings(l, string.ascii_lowercase))
for _ in range(6):
    testcase(random_strings(100, string.ascii_lowercase))

assert testcase_index <= 81

# n = 500 (20%)

for _ in range(5):
    random.shuffle(words)
    testcase(words[:500])
testcase(sorted(words)[:500])
testcase(sorted(words)[-500:])
testcase(strings(500, 'ab'))
testcase(strings(500, 'xyz'))
testcase(strings(500, 'pqrs'))
testcase(strings(500, 'coeui'))
testcase(strings(500, string.ascii_lowercase))
testcase(random_strings(500, 'ab'))
testcase(random_strings(500, 'xyz'))
testcase(random_strings(500, 'pqrs'))
for _ in range(5):
    testcase(random_strings(500, string.ascii_lowercase))

assert testcase_index == 101

