import sys
sys.setrecursionlimit(10**9)
n, m = map(int, sys.stdin.readline().split())

preorder = list(map(int, sys.stdin.readline().split()))
inorder = list(map(int, sys.stdin.readline().split()))

loc = [ [] for i in range(n+1) ]
children = [ [] for i in range(n+1) ]
for i, x in enumerate(inorder):
    loc[inorder[i]].append(i)

# global pat
pat = 0

# def parse(parent, l,r):
#     global pat

#     root = preorder[pat]
#     pat += 1

#     if parent is not None:
#         children[parent].append(root)

#     if l != r:
#         for x in loc[root]:
#             parse(root, l, x-1)
#             l = x+1

#         parse(root, l,r)

# parse(None, 0,m-1)

S = [(None, 0, m-1)]
while S:
    parent, l, r = S.pop()

    root = preorder[pat]
    pat += 1

    if parent is not None:
        children[parent].append(root)

    if l != r:
        here = []
        for x in loc[root]:
            here.append((l,x-1))
            l = x+1

        here.append((l,r))

        for (l,r) in here[::-1]:
            S.append((root, l, r))

for i in range(1,n+1):
    print('%d: %s' % (i, ' '.join(map(str, children[i]))))

