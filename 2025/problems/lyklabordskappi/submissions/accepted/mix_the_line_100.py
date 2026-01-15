n, l, t = map(int, input().split())
words = input().split()

letters_per_line = l * t

ans = []

letters_left = letters_per_line
line = []

ans: list[list[str]] = []

if not all([len(word) + 1 <= letters_per_line for word in words]):
    print("/ff")
else:
    i = 0
    while i < n:
        length = len(words[i]) + 1
        if length <= letters_left:
            letters_left -= length
            line.append(words[i])
            i += 1
        else:
            ans.append(line)
            line = []
            letters_left = letters_per_line

    ans.append(line)

if len(ans) > 1:
    length = 0
    for word in ans[-1]:
        length += len(word) + 1

    if length + len(ans[-2][-1]) + 1 <= letters_per_line:
        ans[-1].insert(0, ans[-2][-1])
        ans[-2].pop()

for words in ans:
    print(" ".join(words))
