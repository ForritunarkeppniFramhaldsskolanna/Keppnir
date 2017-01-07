
"""
pyfgcrl
aoeuidhtns
qjkxbmwvz
"""

import sys
import random
import string

alph = random.choice(['pyfgcrl', 'aoeuidhtns', 'qjkxbmwvz', string.digits])
sys.stdout.write(''.join(random.choice(alph) for i in range(random.randint(5,100))) + '\n')
