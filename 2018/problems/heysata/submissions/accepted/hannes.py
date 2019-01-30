import sys

n = int(sys.stdin.readline())

k = sys.stdin.readline().strip()

heystack = sys.stdin.readline().strip()

if k in heystack:
    print("Unnar fann hana!")
else:
    print("Unnar fann hana ekki!")