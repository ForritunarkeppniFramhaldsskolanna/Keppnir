#!/usr/bin/python3
n = int(input()) # Read the number of words from input
words = input().split() # Read the words and split them into a list

# Process the words to create the abbreviation
abbreviation = ""
for word in words:
    if word[0].isupper(): # If the first letter is uppercase
        abbreviation += word[0] # Add it to the abbreviation
    else:
        continue # Otherwise, skip the word

# Print the abbreviation
print(abbreviation)

