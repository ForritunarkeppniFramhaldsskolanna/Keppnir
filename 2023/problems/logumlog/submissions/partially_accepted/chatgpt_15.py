#!/usr/bin/python3
# I was unable to get chatgpt to give me code which solved the task but it made plenty of decent suggestions
# I asked it to solve the first subtask afterwards
def is_same_melody(melody1, melody2):
    if len(melody1) != len(melody2):
        return False

    for i in range(len(melody1)):
        if melody1[i] != melody2[i]:
            return False

    return True

n = int(input())
print("Jebb" if is_same_melody(input().split(), input().split()) else "Neibb")
