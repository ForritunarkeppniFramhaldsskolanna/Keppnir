#!/env/usr/bin python3
s = input()
m = input().split()
a = []
for i in range(len(m)):
    a.append(True)
for e in s:
    for i in range(len(m)):
        for f in m[i]:
            if e == f:
                a[i] = False
                break

for i in range(len(m)):
    if a[i]: print(m[i], end = ' ')
    else:
        for _ in range(len(m[i])): print("*", end = '')
        print(end = ' ')
print()
