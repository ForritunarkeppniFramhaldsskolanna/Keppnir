def solve():
    import sys

    # Read the input line, strip trailing newline
    line = sys.stdin.readline().rstrip("\n")

    # Convert to lowercase
    line = line.lower()

    # Define replacements for Icelandic characters and accented letters
    replacements = {
        "á": "a",
        "é": "e",
        "í": "i",
        "ó": "o",
        "ú": "u",
        "ý": "y",
        "ö": "o",
        "æ": "ae",
        "ð": "d",
        "þ": "th",
        "à": "a",
        "è": "e",
        "ì": "i",
        "ò": "o",
        "ù": "u",  # in case of other accented vowels
        # ... add any other accented mappings if needed ...
    }

    # Build the result
    result = []
    for ch in line:
        # If it's a known special character, replace it
        if ch in replacements:
            result.append(replacements[ch])
        # Else if it's alphanumeric, keep it
        elif ch.isalnum():
            result.append(ch)
        # Otherwise, skip it (remove punctuation, spaces, etc.)
        else:
            continue

    # Join everything and add ".is"
    domain = "".join(result) + ".is"

    print(domain)


if __name__ == "__main__":
    solve()
