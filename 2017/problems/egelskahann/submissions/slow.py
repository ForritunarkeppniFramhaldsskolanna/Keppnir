n = int(input())
flowers = list(range(n+1))[1:]

i = 1
while(len(flowers) > 1):
    del flowers[i]
    i = (i+1)%len(flowers)

print(flowers[0])
