import sys
import random

sys.setrecursionlimit(1000000)

if len(sys.argv) > 5:
    random.seed(int(sys.argv[-1]))

tp = sys.argv[1]
min_n = eval(sys.argv[2])
max_n = eval(sys.argv[3])
edge = sys.argv[4]

def mk_bin_tree(n):
    if n == 1:
        return (0, None, None)
    else:
        left_size = 0
        if edge == "left":
            left_size = n-2
        elif edge == "right":
            left_size = 1
        elif edge == "complete":
            left_size = (n-1)//2
        while left_size % 2 == 0:
            left_size = random.randint(1, n-1)
        return (0, mk_bin_tree(left_size), mk_bin_tree(n-1-left_size))

def assign_ids(tree, ids, at):
    if tree == None:
        return
    L = assign_ids(tree[1], ids, at)
    val = ids[at[0]]
    at[0] += 1
    R = assign_ids(tree[2], ids, at)
    return (val, L, R)



def can_tree(n):
    if n in [0, 2]:
        return False
    return True


def random_partition(n):
    if n <= 1:
        assert False
    if n == 2:
        return [1,1]
    if n == 3:
        return [1,1,1]
    if n == 4:
        return [1,1,1,1]
    if n >= 5:
        if edge == "wide":
            return [1]*n
        elif edge == "center":
            return [1,n-2,1]
        A = []
        A.append(random.randint(1, n-1))
        if A[0] == 2:
            A[0] == 1
        remaining = n-A[0]
        while remaining > 0:
            A.append(random.randint(1, remaining))
            if A[-1] == 2:
                A[-1] == 1
            remaining -= A[-1]
        random.shuffle(A)
        return A
    
def mk_tree(n, ids, at):
    if n == 1:
        val = ids[at[0]]
        at[0] += 1
        return (val,)
        
    partition = [0]
    while any(not can_tree(x) for x in partition):
        partition = random_partition(n-1)
    val = ids[at[0]]
    at[0] += 1
    return (val,) + tuple(mk_tree(x, ids, at) for x in partition)

tree = None
n = 0
m = 0

if tp == "BST" or tp == "BT":
    while n % 2 == 0:
        n = random.randint(min_n, max_n)
    tree = mk_bin_tree(n)
    ids = [i for i in range(1, n+1)]
    if tp != "BST":
        random.shuffle(ids)
    tree = assign_ids(tree, ids, [0])
elif tp == "GT":
    while not can_tree(n):
        n = random.randint(min_n, max_n)
    ids = [i for i in range(1, n+1)]
    random.shuffle(ids)
    tree = mk_tree(n, ids, [0])


def preorder(tree, result):
    if tree == None:
        return
    result.append(tree[0])
    for i in range(1, len(tree)):
        preorder(tree[i], result)

def inorder(tree, result):
    if tree == None:
        return
    if len(tree) == 1:
        result.append(tree[0])
        return
    inorder(tree[1], result)
    for i in range(2, len(tree)):
        result.append(tree[0])
        inorder(tree[i], result)

def postorder(tree, result):
    if tree == None:
        return
    for i in range(1, len(tree)):
        postorder(tree[i], result)
    result.append(tree[0])

preL = []
inL = []
postL = []

preorder(tree, preL)
inorder(tree, inL)
postorder(tree, postL)

m = len(inL)
print(n, m)
print(' '.join(str(i) for i in preL))
print(' '.join(str(i) for i in inL))
print(' '.join(str(i) for i in postL))
