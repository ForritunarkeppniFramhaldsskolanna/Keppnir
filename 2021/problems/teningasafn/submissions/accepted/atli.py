#!python3
mod = 10 ** 9 + 7

n, k = [int(x) for x in input().strip().split()]

fct = [1 for i in range(k + 2)]
for i in range(1, k + 2):
    fct[i] = fct[i - 1] * i % mod

B = [1 for i in range(k + 1)]
for i in range(1, k + 1):
    sm = 0
    for j in range(i):
        sm += fct[i + 1] * pow(fct[j], -1, mod) * pow(fct[i + 1 - j], -1, mod) * B[j]
        sm %= mod
    sm *= pow(mod - i - 1, -1, mod)
    B[i] = sm % mod

sm = 0

for i in range(k + 1):
    trm = fct[k + 1] * pow(fct[i], -1, mod) * pow(fct[k + 1 - i], -1, mod) % mod
    trm *= B[i] * pow(n + 1, k + 1 - i, mod)
    trm %= mod
    sm += trm
    sm %= mod

sm *= pow(k + 1, -1, mod)
sm %= mod

print(sm)
