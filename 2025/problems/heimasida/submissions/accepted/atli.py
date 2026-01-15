import string

wanted = set(string.ascii_lowercase + "0123456789")
change = {"á": "a", "ð": "d", "é": "e", "í": "i", "ó": "o", "ú": "u", "ý": "y", "þ": "th", "æ": "ae", "ö": "o"}
outp = []
for c in input().lower():
    if c in change:
        outp.append(change[c])
    elif c in wanted:
        outp.append(c)
print("".join(outp) + ".is")
