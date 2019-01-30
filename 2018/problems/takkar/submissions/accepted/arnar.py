import sys
line = sys.stdin.readline()
a = int(line)
line = sys.stdin.readline()
b = int(line)
if a < b:
    print("FAKE NEWS!")
elif a > b:
    print("MAGA!")
else:
    print("WORLD WAR 3!")
