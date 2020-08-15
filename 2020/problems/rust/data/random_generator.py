import sys
import random


min_n = eval(sys.argv[1])
max_n = eval(sys.argv[2])
min_k = eval(sys.argv[3])
max_k = eval(sys.argv[4])
tp = sys.argv[5]

if tp == "special":
    n,k = 0,0
    while n % 2 != 1:
        n = random.randint(min_n, max_n)
    while k % 2 != 1:
        k = random.randint(min(min_k, n), min(max_k, n))

    print(str(n) + " " + str(k))
    for x in range(n):
        A = []
        for y in range(n):
            if x%2 == 1 and y%2 == 1:
                A.append(random.choice(["#"] + [str(i) for i in range(1,10)]))
            else:
                A.append(".")
        print(''.join(A))
else:
    n = random.randint(min_n, max_n)
    k = random.randint(min(min_k,n), min(max_k,n))


    print(str(n) + " " + str(k))
    for x in range(n):
        s = ""
        for y in range(n):
            nm = random.randint(1,10)
            if nm == 1:
                s += "#"
            elif nm == 2:
                s += str(random.randint(1,9))
            else:
                s += "."
        print(s)

