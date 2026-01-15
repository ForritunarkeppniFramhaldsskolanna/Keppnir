n, m = map(int, input().strip().split())
for _ in range(n):
    _ = input()
rep = input().strip()
rep = rep.replace("-,", "0,")
for _ in range(m):
    print(rep)
