#!/usr/bin/python3
def count_letters(input_string):
    # Count only ASCII letters (both lowercase and uppercase)
    letter_count = sum(c.isalpha() for c in input_string)
    return letter_count

# Counting letters in the input
result = count_letters(input())

# Outputting the result
print(result)

