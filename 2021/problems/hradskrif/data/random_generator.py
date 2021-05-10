import sys
import random
import string

random.seed(int(sys.argv[-1]))

group = sys.argv[1]

words = []
with open("words_alpha.txt", "r") as f:
    for line in f:
        words.append(line.strip().upper())

if group == "A":
    words = list(filter(lambda x: len(x) <= 10, words))
    sentence = list()
    n = random.randint(1, 10)
    while len(sentence) < n:
        selected = random.choice(words)
        sentence.append(selected)
    sys.stdout.write('{}\n'.format(n))
    sys.stdout.write(' '.join(sentence))
    sys.stdout.write('\n')
elif group == "A-dup":
    words = list(filter(lambda x: len(x) <= 10, words))
    random.shuffle(words)
    words = words[:4]
    sentence = list()
    n = random.randint(1, 10)
    while len(sentence) < n:
        selected = random.choice(words)
        sentence.append(selected)
    sys.stdout.write('{}\n'.format(n))
    sys.stdout.write(' '.join(sentence))
    sys.stdout.write('\n')
elif group == "B":
    words = list(filter(lambda x: len(x) <= 10, words))
    sentence = list()
    sm = -1
    limit = random.randint(100, 1000000)
    while True:
        selected = random.choice(words)
        if sm + len(selected) + 1 > limit:
            break
        sentence.append(selected)
        sm += 1 + len(selected)
    sys.stdout.write('{}\n'.format(len(sentence)))
    sys.stdout.write(' '.join(sentence))
    sys.stdout.write('\n')
elif group == "C":
    def genword(n):
        return ''.join(random.choice(string.ascii_uppercase) for _ in range(n))
    sentence = list()
    sm = -1
    limit = 1000000
    while True:
        selected = genword(random.randint(1, 10000))
        if sm + len(selected) + 1 > limit:
            break
        sentence.append(selected)
        sm += 1 + len(selected)
    sys.stdout.write('{}\n'.format(len(sentence)))
    sys.stdout.write(' '.join(sentence))
    sys.stdout.write('\n')
else:
    assert False
