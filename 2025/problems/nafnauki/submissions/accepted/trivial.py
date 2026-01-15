#!/usr/bin/python3
name = input().strip()
if name[-2] == ".":
    print(name[-2:])
elif name[-3] == ".":
    print(name[-3:])
elif name[-4] == ".":
    print(name[-4:])
elif name[-5] == ".":
    print(name[-5:])
elif name[-6] == ".":
    print(name[-6:])
else:
    assert False
