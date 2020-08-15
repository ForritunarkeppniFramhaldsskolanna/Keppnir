import sys
import random

random.seed(int(sys.argv[-1]))

n = eval(sys.argv[1])
k = eval(sys.argv[2])
initial = sys.argv[3]
state = sys.argv[4]

# if state == 'random':
#     state = (state, random.randint(1,k//20))
# else:

def random_len():
    return random.randint(1,(k+19)//20)

def random_state():
    return (random.choice(['random', 'down']), random_len())

state = (state, random_len())

sys.stdout.write('%d %d\n' % (n,k))

if initial == 'empty':
    arr = ['.']*n
elif initial == 'random':
    arr = [ random.choice(['.','o']) for _ in range(n) ]
elif initial == 'full':
    arr = ['o']*n

sys.stdout.write('%s\n' % ''.join(arr))
sys.stdout.write('%s\n' % ('o'*n))

empty = [ i for i in range(n) if arr[i] == '.' ]
full = [ i for i in range(n) if arr[i] == 'o' ]

def down():
    if not full:
        return False
    at = random.randint(0, len(full)-1)
    full[at], full[-1] = full[-1], full[at]
    cur = full.pop()

    sys.stdout.write('U 1 %d\n' % (cur+1))
    empty.append(cur)
    return True

def up():
    if not empty:
        return False
    at = random.randint(0, len(empty)-1)
    empty[at], empty[-1] = empty[-1], empty[at]
    cur = empty.pop()

    sys.stdout.write('U 1 %d\n' % (cur+1))
    full.append(cur)
    return True

for t in range(k):
    if t % 2 == 0:
        sys.stdout.write('Q\n')
        continue

    while True:
        if state[0] == 'down':
            if down():
                break
            state = random_state()
        elif state[0] == 'random':
            if random.randint(0,1) == 0:
                assert down() or up()
                break
            else:
                assert up() or down()
                break
        else:
            assert False

    if state[1] == 1:
        state = random_state()
    else:
        state = (state[0], state[1]-1)

