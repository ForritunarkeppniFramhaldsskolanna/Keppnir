import sys
import random
import string

sys.stdout.write("{}.{}\n".format(random.randint(0,100), ''.join(random.Random().sample(string.digits, random.randint(1,5)))))
