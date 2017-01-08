import sys
lines = sys.stdin.readlines()

val = {}

for l in lines[1:]:
    parts = l.split()
    if parts[0] == 'INNTAK':
        val[parts[1]] = parts[2] == 'SATT'
    elif parts[0] == 'UTTAK':
        print parts[1], 'SATT' if val[parts[1]] else 'OSATT'
    elif parts[0] == 'OG':
        val[parts[3]] = val[parts[1]] and val[parts[2]]
    elif parts[0] == 'EDA':
        val[parts[3]] = val[parts[1]] or val[parts[2]]
    elif parts[0] == 'EKKI':
        val[parts[2]] = not val[parts[1]]

