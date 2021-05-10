import random

rolls = []
l = 0

while True:
    dice = []
    for i in range(random.randint(1, 5)):
        dice.append(random.choice(['-', '+']))
        if random.randint(1, 4) == 1:
            dice.append(str(random.randint(1, 9999)))
        else:
            n = random.randint(1, 9999)
            m = random.randint(1, 9999)
            if random.randint(1, 4) == 4:
                dice.append(str(n) + 'd' + str(m) + '!')
            else:
                dice.append(str(n) + 'd' + str(m))
    if dice[0] == '+':
        dice = dice[1:]
    res = ''.join(dice)
    l += len(res)
    if l > 10 ** 5:
        break
    rolls.append(res)

print(len(rolls))
for roll in rolls:
    print(roll)
    print(random.randint(-10 ** 18, 10 ** 18))
