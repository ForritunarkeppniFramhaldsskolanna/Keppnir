#!/usr/bin/python3


def convert_text(text, from_layout, to_layout):
    """
    Converts text from one keyboard layout to another.

    Args:
      text: The text to convert.
      from_layout: The keyboard layout the text was written in.
      to_layout: The keyboard layout the user intended to use.

    Returns:
      The converted text.
    """
    # Load the keyboard layout conversion table
    conversion_table = _load_conversion_table()

    # Convert the text character by character
    converted_text = ""
    for char in text:
        if char in conversion_table[from_layout]:
            converted_text += conversion_table[from_layout][char]
        else:
            # If the character is not found in the table, assume it's the same
            converted_text += char

    # Replace multiple consecutive spaces with a single space
    return " ".join(converted_text.split())


def _load_conversion_table():
    """
    Loads the keyboard layout conversion table from the provided data.

    Returns:
      A dictionary where the keys are the layout names and the values are dictionaries mapping
      characters in the corresponding layout to their equivalents in other layouts.
    """
    # Replace this with your actual method to load the data from the TSV file
    # This is just an example showing the expected format
    conversion_table = {
        "qwerty": {
            "~": "~",
            "1": "1",
            "2": "2",
            "3": "3",
            "4": "4",
            "5": "5",
            "6": "6",
            "7": "7",
            "8": "8",
            "9": "9",
            "0": "0",
            "-": "-",
            "=": "=",
            "q": "q",
            "w": "w",
            "e": "e",
            "r": "r",
            "t": "t",
            "y": "y",
            "u": "u",
            "i": "i",
            "o": "o",
            "p": "p",
            "[": "[",
            "]": "]",
            "a": "a",
            "s": "s",
            "d": "d",
            "f": "f",
            "g": "g",
            "h": "h",
            "j": "j",
            "k": "k",
            "l": "l",
            ";": ";",
            " ": " ",
            "z": "z",
            "x": "x",
            "c": "c",
            "v": "v",
            "b": "b",
            "n": "n",
            "m": "m",
            ",": ",",
            ".": ".",
            "/": "/",
        },
        "dvorak": {
            "~": "~",
            "1": "1",
            "2": "2",
            "3": "3",
            "4": "4",
            "5": "5",
            "6": "6",
            "7": "7",
            "8": "8",
            "9": "9",
            "0": "0",
            "[": "-",
            "]": "=",
            " ": "q",
            ",": "w",
            ".": "e",
            "p": "r",
            "y": "t",
            "f": "y",
            "g": "u",
            "c": "i",
            "r": "o",
            "l": "p",
            "/": "[",
            "=": "]",
            "a": "a",
            "o": "s",
            "e": "d",
            "u": "f",
            "i": "g",
            "d": "h",
            "h": "j",
            "t": "k",
            "n": "l",
            "s": ";",
            "-": " ",
            ";": "z",
            "q": "x",
            "j": "c",
            "k": "v",
            "x": "b",
            "b": "n",
            "m": "m",
            "w": ",",
            "v": ".",
            "z": "/",
        },
        "bjarki": {
            "0": "~",
            "2": "1",
            "4": "2",
            "8": "3",
            "6": "4",
            "1": "5",
            "3": "6",
            "5": "7",
            "7": "8",
            "9": "9",
            "=": "0",
            "-": "-",
            "/": "=",
            "b": "q",
            "j": "w",
            "a": "e",
            "r": "r",
            "k": "t",
            "i": "y",
            "g": "u",
            "u": "i",
            "s": "o",
            "t": "p",
            ".": "[",
            ",": "]",
            "l": "a",
            "o": "s",
            "e": "d",
            "m": "f",
            "p": "g",
            "d": "h",
            "c": "j",
            "n": "k",
            "v": "l",
            "q": ";",
            ";": " ",
            "[": "z",
            "]": "x",
            "y": "c",
            "z": "v",
            "h": "b",
            "w": "n",
            "f": "m",
            "x": ",",
            " ": ".",
            "~": "/",
        },
    }
    return conversion_table


# Example usage
from_layout, _, to_layout = input().split()
text = input()
converted_text = convert_text(text, from_layout, to_layout)
print(converted_text)  # Output: this is an example
