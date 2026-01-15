n, l, t = map(int, input().split())
words = input().split()

letters_per_line = l * t

ans = []

letters_left = letters_per_line
line = []

if not all([len(word) + 1 <= letters_per_line for word in words]):
    print("/ff")
    print("Trailing")
else:
    i = 0
    while i < n:
        length = len(words[i]) + 1
        if length <= letters_left:
            letters_left -= length
            line.append(words[i])
            i += 1
        else:
            print(" ".join(line))
            line = []
            letters_left = letters_per_line

    print(" ".join(line))
