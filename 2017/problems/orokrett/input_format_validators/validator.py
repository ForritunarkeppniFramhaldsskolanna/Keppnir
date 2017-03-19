import sys
import re

s = sys.stdin.readline()
assert s[-1] == '\n'
s = s[:-1]
clauses = s.split(' EDA ')

assert 1 <= len(clauses) <= 100

vs = set()
for clause in clauses:
    assert clause[0] == '('
    assert clause[-1] == ')'
    clause = clause[1:-1]

    variables = clause.split(' OG ')
    # assert 1 <= len(variables) <= 100

    for variable in variables:
        if variable[0] == '!':
            variable = variable[1:]

        assert re.match('^[a-z]{1,10}$', variable)
        # assert len(variable) == 1
        # assert ord('a') <= ord(variable) <= ord('j')
        vs.add(variable)

assert len(vs) <= 100
assert sys.stdin.read() == ''

sys.exit(42)
