n, symb, m = input().split()
n = int(n)
m = int(m)

if n > m:
    print(">")
elif n < m:
    print("<")
elif n == m:
    print("Goggi svangur!")
