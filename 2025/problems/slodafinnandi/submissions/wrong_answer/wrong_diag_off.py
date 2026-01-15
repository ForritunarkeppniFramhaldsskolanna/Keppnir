s = int(input()) // 5
tot = 0
for dy in range(-s, s + 1):
    extra = s - abs(dy)
    side = min(abs(dy) // 2, extra)
    extra -= side
    xstep = 2 * side + extra
    tot += 2 * xstep + 1
print(tot)
