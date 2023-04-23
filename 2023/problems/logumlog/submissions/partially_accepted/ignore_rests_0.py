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
    return note_text[0], note_text[1:octave_index], int(note_text[octave_index:len(note_text)])

def text_to_note(note_text: str):
    base, accidentals, octave = base_accidentals_octave(note_text)
    n = octave * SEMITONES_IN_OCTAVE
    for i, c in enumerate(NOTE_CHARS):
        if c == base:
            break
        n += MAJOR[i]
    n += accidentals.count(SHARP) - accidentals.count(FLAT)
    return Note(n)

class Note:
    def __init__(self, n):
        self.n = n

    def __str__(self):
        n = self.n
        octave = n // SEMITONES_IN_OCTAVE
        n = n % SEMITONES_IN_OCTAVE
        ind = 0
        while MAJOR[ind] <= n:
            n -= MAJOR[ind]
            ind += 1
        base = NOTE_CHARS[ind]
        accidental = SHARP if n == 1 else ""
        return "{}{}{}".format(base, accidental, octave)

    def transpose(self, step):
        return Note(self.n + step)

    def is_perfectly_harmonious(self, other):
        return self.n % SEMITONES_IN_OCTAVE == other.n % SEMITONES_IN_OCTAVE

if __name__ == "__main__":
    n = int(input())

    # TODO: Handle rests properly
    song1_with_rests = input().split()
    song2_with_rests = input().split()
    song1 = [text_to_note(note).n for note in song1_with_rests if note != REST]
    song2 = [text_to_note(note).n for note in song2_with_rests if note != REST]
    diff1 = [song1[i] - song1[i-1] for i in range(1, len(song1))]
    diff2 = [song2[i] - song2[i-1] for i in range(1, len(song2))]
    print("Jebb" if diff1 == diff2 else "Neibb")
