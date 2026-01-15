n = int(input())
idnam = []
for _ in range(n):
    nam, _, _, _ = input().split(", ")
    idnam.append(nam)
idnam.sort()
for nam in idnam:
    print(nam)
