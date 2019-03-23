import sys
import random
import string
# min_n
# max_n
# seed
chars = ' ' + string.ascii_letters + string.digits + string.punctuation
if len(sys.argv) > 3:
    random.seed(int(sys.argv[3]))
n = random.randint(int(sys.argv[1]), int(sys.argv[2]))
print(''.join([random.choice(chars) for _ in range(n)]))
