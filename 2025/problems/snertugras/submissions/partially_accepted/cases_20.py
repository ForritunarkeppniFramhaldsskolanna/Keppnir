def bail():
    print("thralatlega nettengdur")
    exit(0)


h, w = map(int, input().strip().split())
if h * w == 1:
    bail()
mp = [input().strip() for _ in range(h)]
if all("G" not in l for l in mp):
    bail()
if h == 1 or w == 1:
    print(1)
    exit(0)
while mp[0][0] != "S":
    mp[0], mp[1] = mp[1], mp[0]
    if mp[0][0] == "S":
        break
    mp[0] = mp[0][::-1]
    mp[1] = mp[1][::-1]
if mp[0][1] == "G" or mp[1][0] == "G":
    print(1)
    exit(0)
if mp[0][1] == "#" and mp[1][0] == "#":
    bail()
print(2)
