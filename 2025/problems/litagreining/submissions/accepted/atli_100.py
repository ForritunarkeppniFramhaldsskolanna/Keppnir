r, g, b = map(int, input().strip().split())
if r > max(g, b):
    print("raudur")
    exit(0)
if g > max(r, b):
    print("graenn")
    exit(0)
if b > max(r, g):
    print("blar")
    exit(0)
if r == g and g > b:
    print("gulur")
    exit(0)
if r == b and b > g:
    print("fjolubleikur")
    exit(0)
if b == g and g > r:
    print("blagraenn")
    exit(0)
if r == 255:
    print("hvitur")
    exit(0)
if r == 0:
    print("svartur")
    exit(0)
print("grar")
