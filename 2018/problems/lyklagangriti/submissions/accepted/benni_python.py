line = raw_input()
arr1 = []
arr2 = []
for x in line:
    if x == 'L':
        arr2.append(arr1.pop())
    elif x == 'R':
        arr1.append(arr2.pop())
    elif x == 'B':
        arr1.pop()
    else:
        arr1.append(x)
ans = ""
for x in arr1:
    ans += x
arr2.reverse()
for x in arr2:
    ans += x
print(ans)
