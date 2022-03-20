#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

test_type = eval(sys.argv[1])

min_words = 2
max_words = 50

word_list = []
with open("list_of_words.txt", "r") as f:
    word_list = [line.rstrip() for line in f]

if test_type == 1:
    w1 = random.choice(word_list)
    w2 = random.choice(word_list)
    sys.stdout.write(f"{w1[:len(w1)//2]}|{w2[:len(w2)//2]}\n{w1[len(w1)//2:]}|{w2[len(w2)//2:]}\n")
elif test_type == 2:
    words = [random.choice(word_list) for i in range(4)]
    sys.stdout.write(f"{words[0]} |{words[2]}\n{words[1]}| {words[3]}\n")
elif test_type == 3:
    word_count = random.randint(min_words, max_words)
    sen1 = [random.choice(word_list) for i in range(word_count)]
    sen2 = [random.choice(word_list) for i in range(word_count)]
    sys.stdout.write(f"{' '.join(sen1[:len(sen1)//2])} |{' '.join(sen2[:len(sen2)//2])}\n{' '.join(sen1[len(sen1)//2:])}| {' '.join(sen2[len(sen2)//2:])}\n")

