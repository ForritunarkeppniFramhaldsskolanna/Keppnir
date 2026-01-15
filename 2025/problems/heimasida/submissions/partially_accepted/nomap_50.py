import string

wanted = set(string.ascii_lowercase + "0123456789")
outp = []
for c in input().lower():
    if c in wanted:
        outp.append(c)
print("".join(outp) + ".is")
