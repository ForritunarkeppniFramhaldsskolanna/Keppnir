#!/bin/python3
NOTE_CHARS = 'CDEFGAB'
SHARP = '#'
FLAT = 'b'
MAJOR = [2, 2, 1, 2, 2, 2, 1]
MINOR = [2, 1, 2, 2, 1, 2, 2]
SEMITONES_IN_OCTAVE = sum(MAJOR)

REST = "-"

def base_accidentals_octave(note_text: str):
    octave_index = -1
    try:
        octave_index = note_text.index('-')
    except ValueError:
        pass
    return list((note_text[0], note_text[1:octave_index], int(note_text[octave_index:len(note_text)])))

def _standardize(a):
    base, accidentals, octave = a
    if accidentals == "#" and base == "B":
        return "C", "", octave+1
    if accidentals == "#" and base == "E":
        return "F", "", octave
    if accidentals == "b" and base == "C":
        return "B", "", octave-1
    if accidentals == "b" and base == "F":
        return "E", "", octave
    if accidentals != "b":
        return a
    i = NOTE_CHARS.index(base) - 1
    return NOTE_CHARS[i], "#", octave

def standardize(a):
    return list(_standardize(a))

if __name__ == "__main__":
    n = int(input())

    # TODO: Handle rests properly
    song1_with_rests = input().split()
    song2_with_rests = input().split()
    for i, a in enumerate(song1_with_rests):
        b = song2_with_rests[i]
        if a != b and (a == REST or b == REST):
            print("Neibb")
            exit()

    song1 = [standardize(base_accidentals_octave(note)) for note in song1_with_rests if note != REST]
    song2 = [standardize(base_accidentals_octave(note)) for note in song2_with_rests if note != REST]
    
    octave_diff = None
    for i in range(len(song1)):
        if i == 0:
            octave_diff = song2[i][2] - song1[i][2]
        song1[i][2] += octave_diff

    print("Jebb" if song1 == song2 else "Neibb")
