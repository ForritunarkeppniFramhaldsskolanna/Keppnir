ts = int(input())
for t in range(ts):
	ps = input().split(' ')
	n = int(ps[0])
	i = int(ps[1])

	a = 5 * n
	b = 5

	for j in range(i):
		if a >= b:
			a -= b
			b += 10
		else:
			a *= 100
			b = (b // 10) * 100 + 5

	print(b)