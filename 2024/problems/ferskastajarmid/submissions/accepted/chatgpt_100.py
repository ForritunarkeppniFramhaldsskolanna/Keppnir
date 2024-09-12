#!/usr/bin/python3

def freshest_meme_from_input():
    n = int(input().strip())  # Read number of memes
    memes = []
    for _ in range(n):
        line = input().strip().split()
        name = line[0]
        controversiality, coolness = map(int, line[1:])
        memes.append((name, controversiality, coolness))

    # Calculate freshness for each meme
    memes_freshness = [(name, controversiality * coolness) for name, controversiality, coolness in memes]
    # Sort memes by freshness and then alphabetically by name
    memes_sorted = sorted(memes_freshness, key=lambda x: (-x[1], x[0]))
    # Return the name of the freshest meme
    return memes_sorted[0][0]

# This function would be called in an environment where input() can be used to read from standard input.
# For example:
freshest_meme = freshest_meme_from_input()
print(freshest_meme)

