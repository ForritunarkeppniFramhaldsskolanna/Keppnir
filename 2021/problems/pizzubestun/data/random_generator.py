import sys
import random
import string

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

n = random.randint(min_n, max_n)
sys.stdout.write(str(n) + "\n")
seen_names = set()
for i in range(n):
    name_length = random.randint(5, (30)-1)
    random_name = None
    while random_name in seen_names or random_name == None:
        random_name = "".join([random.choice(string.ascii_letters) for x in range(name_length)])
    seen_names.add(random_name)


    random_price = random.randint(1, (10**9)-1)

    sys.stdout.write("%s %d\n" % (random_name, random_price))



