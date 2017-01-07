
s = raw_input()
def bt(at, sofar):
    if at == len(s):
        print(sofar)
    elif s[at] == '?':
        for i in range(10):
            bt(at + 1, sofar + str(i))
    else:
        bt(at + 1, sofar + s[at])

k = s.count('?')
if k >= 5:
    print('Fjoldi: %d' % 10**k)
else:
    bt(0, '')

