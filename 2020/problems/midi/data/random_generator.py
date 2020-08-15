import sys
import random
import string

random.seed(int(sys.argv[-1]))

min_n = eval(sys.argv[1])
max_n = eval(sys.argv[2])
min_sm = eval(sys.argv[3])
max_sm = eval(sys.argv[4])

if min_n == -1:
    msg_len = 1000000
    n = 1000
    sys.stdout.write("%d\n"%n)
    for i in range(n):
        for j in range(msg_len//n):
            sys.stdout.write(random.choice(string.ascii_lowercase))
        sys.stdout.write("\n")
    
else:

    msg_len = random.randint(min_sm, max_sm)
    msg = [random.choice(string.ascii_lowercase) for i in range(msg_len)]

    n = random.randint(min_n, min(msg_len, max_n))

    def randint_low_pref(lo, hi, e=2):
        assert hi >= lo
        if random.randint(0,3) > 0 and hi-lo > 10:
            return random.randint(lo, lo+10)
        else:
            x = random.uniform(0,1)
            x = x**e
            return int(lo + (hi+1-lo)*x)

    rev_msg = msg[::-1]


    at = 0
    sys.stdout.write("%d\n" % n)
    for i in range(n):
        stop = randint_low_pref(at+1, msg_len-n+i+1, 2)
        for j in range(at, stop):
            sys.stdout.write(rev_msg[at])
            at += 1
        if i == n-1:
            while at < msg_len:
                sys.stdout.write(rev_msg[at])
                at += 1
        sys.stdout.write("\n")
        sys.stdout.flush()
