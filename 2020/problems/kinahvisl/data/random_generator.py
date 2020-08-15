import sys
import random
from string import ascii_lowercase
# from tqdm import tqdm

random.seed(int(sys.argv[-1]))

# identical words is int, either 0 or 1, treat it like a boolean
identical_words = int(sys.argv[1])
max_len = eval(sys.argv[2])

word = [random.choice(ascii_lowercase) for i in range(max_len)]
print("".join(word))

if identical_words == 1:
    print("".join(word))
else:
    for i in range(max_len):

        should_flip = random.choice([True, False])

        if should_flip:
            rand_index = random.randint(0, len(word)-1)
            char_list = list(ascii_lowercase)
            char_list.remove(word[i])
            rand_char = random.choice(char_list)
            word[i] = rand_char

    print("".join(word))
