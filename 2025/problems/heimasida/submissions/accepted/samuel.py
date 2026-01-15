from string import ascii_lowercase, digits

allowed_chars = ascii_lowercase + digits

mapping = {
    "ö": "o",
    "æ": "ae",
    "ð": "d",
    "þ": "th",
    "á": "a",
    "é": "e",
    "í": "i",
    "ó": "o",
    "ú": "u",
    "ý": "y",
}

s = input().lower()

for c in s:
    if c in mapping:
        print(mapping[c], end="")
    elif c in allowed_chars:
        print(c, end="")

print(".is")
