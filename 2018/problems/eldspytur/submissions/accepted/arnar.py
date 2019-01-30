import sys
def win(n, k):
    return n%(k+1) != 0
n,k = map(int,sys.stdin.readline().split())
print("Jebb" if win(n,k) else "Neibb")
