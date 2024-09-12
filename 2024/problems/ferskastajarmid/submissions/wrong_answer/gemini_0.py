#!/usr/bin/python3


def get_meme_data():
    """
    Reads meme data from user input.

    Returns:
        A list of dictionaries, where each dictionary describes a meme
        with keys: "name", "controversiality", and "coolness".
    """
    n = int(input())
    memes = []
    for _ in range(n):
        meme_data = input().split()
        memes.append(
            {
                "name": meme_data[0],
                "controversiality": int(meme_data[1]),
                "coolness": int(meme_data[2]),
            }
        )
    return memes


def find_freshest_meme(memes):
    """
    Finds the freshest meme from a list of memes.

    Args:
        memes: A list of dictionaries, where each dictionary describes a meme
               with keys: "name", "controversiality", and "coolness".

    Returns:
        The name of the freshest meme.
    """
    freshest_meme = ""
    highest_freshness = 0

    for meme in memes:
        name = meme["name"]
        freshness = meme["controversiality"] * meme["coolness"]
        if freshness > highest_freshness:
            highest_freshness = freshness
            freshest_meme = name
        elif freshness == highest_freshness and name < freshest_meme:
            freshest_meme = name

    return freshest_meme


# Main program
memes = get_meme_data()
freshest_meme_name = find_freshest_meme(memes)
print(freshest_meme_name)
