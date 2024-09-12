#!/usr/bin/python3
def count_letters(text):
    """Counts the number of letters in the given text."""
    letter_count = 0
    for character in text:
        if character.isalpha():  # Check if character is alphabetic (letter)
            letter_count += 1
    return letter_count


# Read input from the console
text = input()

# Count the letters and print the result
number_of_letters = count_letters(text)
print(number_of_letters)
