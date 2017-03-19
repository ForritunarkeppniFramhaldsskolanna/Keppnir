import sys

def WA():
    sys.exit(43)


with open(sys.argv[1], 'r') as f:
    n,s = map(int,f.readline().split())
    arr = []
    for i in  range(n):
        arr.append(int(f.readline()))

with open(sys.argv[2], 'r') as f:
    ans = f.readline().strip()
x = ans.lower() == "neibb"

try:
    line = sys.stdin.readline()
    y = line.strip().lower() == "neibb"
    if x != y:
        WA()

    if not x:
        ablist = line.strip().split()
        a = int(ablist[0])
        b = int(ablist[1])

        if a == b:
            if arr.count(a) < 2: #if the user inputs the same numer twice, there have to be at least 2 occurances in arr 
                WA()


        if a not in arr or b not in arr:
            WA()
        if a+b != s:
            WA()

except:
    WA()


sys.exit(42)

