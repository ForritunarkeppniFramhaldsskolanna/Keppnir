#!/usr/bin/python3
dat = [
""" x
x x
 x
""",
"""  x
 / \\
x   x
 \\ /
  x
""",
"""   x
  / \\
 /   \\
x     x
 \\   /
  \\ /
   x
""",
"""    x
   / \\
  /   \\
 /     \\
x       x
 \\     /
  \\   /
   \\ /
    x
"""
]
n = int(input())
for l in dat[n].split('\n')[:-1]:
    print(l.rstrip())
