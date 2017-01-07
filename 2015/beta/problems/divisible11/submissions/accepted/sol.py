n = int(raw_input())
orig = n

while n >= 10:
    print(n)
    d = n % 10
    n = n // 10
    n -= d

print(n)

if n == 0:
    print('Talan %d er deilanleg med 11.' % orig)
else:
    print('Talan %d er ekki deilanleg med 11.' % orig)

