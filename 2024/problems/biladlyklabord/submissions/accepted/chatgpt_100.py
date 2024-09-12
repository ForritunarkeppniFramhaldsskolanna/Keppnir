#!/usr/bin/python3
def remove_adjacent_duplicates(s):
    result = ""
    # Iterate through each character in the string
    for char in s:
        # If the result is not empty and the last character in the result is the same as the current character, skip it
        if result and result[-1] == char:
            continue
        # Otherwise, add the current character to the result
        else:
            result += char
    return result

print(remove_adjacent_duplicates(input()))
