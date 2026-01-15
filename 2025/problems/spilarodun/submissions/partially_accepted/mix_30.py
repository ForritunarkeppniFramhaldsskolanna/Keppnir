n = int(input())
idnam = []
for _ in range(n):
    nam, curid, _, _ = input().split(", ")
    idnam.append((curid, nam))
sortby = input()
if sortby[0] == "n":
    idnam.sort(key=lambda x: x[1])
else:
    idnam.sort()
for _, nam in idnam:
    print(nam)
