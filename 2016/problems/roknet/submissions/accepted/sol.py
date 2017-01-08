import sys
lines = sys.stdin.readlines()

def var(s):
    return 'var_' + s

poss = {}

# for solution in range(2**5):
solat = 0
outp = []

for l in lines[1:]:
    parts = l.split()
    if parts[0] == 'INNTAK':
        if parts[2] == 'SATT':
            parts[2] = 'True'
        elif parts[2] == 'OSATT':
            parts[2] = 'False'
        else:
            assert solat < 5
            parts[2] = str(bool(solution & (1<<solat)))
            solat += 1
        locals()[var(parts[1])] = eval(parts[2])
    elif parts[0] == 'UTTAK':
        outp.append(parts[1])
        poss.setdefault(parts[1], set())
        poss[parts[1]].add(locals()[var(parts[1])])
        # print(parts[1], locals()[var(parts[1])])
    elif parts[0] == 'OG':
        locals()[var(parts[3])] = eval('%s and %s' % (var(parts[1]), var(parts[2])))
    elif parts[0] == 'EDA':
        locals()[var(parts[3])] = eval('%s or %s' % (var(parts[1]), var(parts[2])))
    elif parts[0] == 'EKKI':
        locals()[var(parts[2])] = eval('not %s' % var(parts[1]))
    else:
        assert False

for o in outp:
    if len(poss[o]) == 1:
        print('%s %s' % (o, 'SATT' if list(poss[o])[0] else 'OSATT'))
    else:
        print('%s ?' % o)

