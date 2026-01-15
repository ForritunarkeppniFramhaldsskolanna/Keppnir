n = int(input())
idnam = []
for _ in range(n):
    nam, curid, _, _ = input().split(", ")
    idnam.append((curid, nam))
idnam.sort()
for _, nam in idnam:
    print(nam)
