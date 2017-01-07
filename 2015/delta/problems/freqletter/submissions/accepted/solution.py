from collections import Counter

s = raw_input()
while s:
    cnt = Counter(s)
    m = max(cnt.values())
    for k,v in sorted(cnt.items()):
        if v == m:
            s = ''.join([ c for c in s if c != k ])
            if s:
                print(s)
            break

