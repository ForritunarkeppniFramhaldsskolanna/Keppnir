mem = dict()
mem[1] = 1
def dp(n):
    if n in mem:
        return mem[n]
    res = 0
    if n % 2 == 0:
        res = 2*dp(n//2)-1
    else:
        res = 2*dp(n//2)+1
    mem[n] = res
    return res
print(dp(int(input())))
