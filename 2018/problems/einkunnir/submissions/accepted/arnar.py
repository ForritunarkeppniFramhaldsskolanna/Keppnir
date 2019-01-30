import sys

def f(n):
    n = int(n*20)
    if n % 10 >= 5:
        return float(n+10-n%10)/20
    else:
        return float(n-n%10)/20

n, s = map(int, sys.stdin.readline().strip().split())
correct = sys.stdin.readline().strip().split()
for i in range(s):
    name = sys.stdin.readline().strip()
    answers = sys.stdin.readline().strip().split()
    grade = f(10*sum([answers[i] == correct[i] for i in range(n)])/float(n))
    sys.stdout.write("%s: %.1f\n"%(name, grade))
