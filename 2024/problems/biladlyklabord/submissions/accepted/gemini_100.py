#!/usr/bin/python3


def filter_keystrokes(s):
    """
    Filters out duplicate characters in a string.

    Args:
      s: The input string.

    Returns:
      The filtered string with no adjacent duplicate characters.
    """
    prev_char = None
    filtered_string = ""
    for char in s:
        if char != prev_char:
            filtered_string += char
        prev_char = char
    return filtered_string


# Example usage
s = input()
filtered_s = filter_keystrokes(s)
print(filtered_s)  # Output: hello world
