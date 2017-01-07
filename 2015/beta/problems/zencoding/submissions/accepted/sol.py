import sys

def sol(s):
    if s == '': return ''
    tag = s.split('+')[0].split('>')[0]
    tlen = len(tag)
    op = s[len(tag):len(tag)+1]
    res = sol(s[tlen+1:]) if op == '>' else ''
    splt = tag.split('*')
    tag = splt[0]
    cnt = 1 if len(splt) == 1 else int(splt[1])
    res = '<%s>%s</%s>' % (tag, res, tag)
    res *= cnt
    if op == '+': res += sol(s[tlen+1:])
    return res

print(sol(sys.stdin.readline().rstrip()))
