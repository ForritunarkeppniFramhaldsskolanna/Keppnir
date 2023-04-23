#!/usr/bin/python3
import sys
import random


NOTE_CHARS = 'CDEFGAB'
SHARP = '#'
FLAT = 'b'
REST = None
MAJOR = [2, 2, 1, 2, 2, 2, 1]
MINOR = [2, 1, 2, 2, 1, 2, 2]
JAPANESE = [2, 1, 4, 1, 4]
HARMONIC_MAJOR = [2, 2, 1, 2, 1, 3, 1]
HARMONIC_MINOR = [2, 1, 2, 2, 1, 3, 1]
PHRYGIAN_DOMINANT = [1, 3, 1, 2, 1, 2, 2]

SCALE_TYPES = [MAJOR, MINOR, JAPANESE, HARMONIC_MAJOR, HARMONIC_MINOR, PHRYGIAN_DOMINANT]
SEMITONES_IN_OCTAVE = sum(MAJOR)
for scale in SCALE_TYPES:
    assert sum(scale) == SEMITONES_IN_OCTAVE

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

def sharpify(note_text):
    base, accidentals, octave = base_accidentals_octave(note_text)
    if accidentals == "":
        if base == "C":
            return "{}{}{}".format("B", "#", octave-1)
        elif base == "F":
            return "{}{}{}".format("E", "#", octave)
    return note_text

def flatify(note_text):
    base, accidentals, octave = base_accidentals_octave(note_text)
    if accidentals == "#":
        assert base not in "BE"
        ind = (NOTE_CHARS.index(base) + 1) % len(NOTE_CHARS)
        return "{}{}{}".format(NOTE_CHARS[ind], "b", octave)
    elif accidentals == "":
        if base == "B":
            return "{}{}{}".format("C", "b", octave+1)
        elif base == "E":
            return "{}{}{}".format("F", "b", octave)
    return note_text
        

class Note:
    def __init__(self, n=None):
        self.n = n

    def __str__(self):
        return self.to_string()

    def to_string(self, style="standard"):
        if self.n is None:
            return "-"
        n = self.n
        octave = n // SEMITONES_IN_OCTAVE
        n = n % SEMITONES_IN_OCTAVE
        ind = 0
        while MAJOR[ind] <= n:
            n -= MAJOR[ind]
            ind += 1
        base = NOTE_CHARS[ind]
        accidental = SHARP if n == 1 else ""
        result = "{}{}{}".format(base, accidental, octave)
        if style == "flatify":
            result = flatify(result)
        elif style == "sharpify":
            result = sharpify(result)
        return result

    def transpose(self, step):
        if self.n is None:
            return Note()
        return Note(self.n + step)

    def is_perfectly_harmonious(self, other):
        if self.n is None or other.n is None:
            return self.n == other.n
        return self.n % SEMITONES_IN_OCTAVE == other.n % SEMITONES_IN_OCTAVE

    def is_rest(self):
        return self.n is None
    
    def __le__(self, other):
        if self.n is None:
            return other.n is not None
        if other.n is None:
            return False
        return self.n < other.n

    def __eq__(self, other):
        return self.n == other.n

def random_char():
    return random.choice(NOTE_CHARS)

def random_octave_for_char(c):
    mn, mx = 1, 7
    if c in 'AB':
        mn -= 1
    if c in 'C':
        mx += 1
    return random.randint(mn, mx)

class Scale:
    def __init__(self, base, steps):
        self.base_note = base
        self.steps = steps
        self.notes = list()
        cur = self.base_note
        for step in steps:
            self.notes.append(cur)
            cur = cur.transpose(step)

    def __contains__(self, note):
        return any(x.is_perfectly_harmonious(note) for x in self.notes)

    def random_note(self, allow_rests=False, min_note=None, max_note=None):
        if min_note is None:
            min_note = text_to_note('A0')
        if max_note is None:
            max_note = text_to_note('C8')
        result = Note()
        if allow_rests and random.uniform(0,1) <= 0.05:
            return result
        while not (MIN_NOTE <= result <= MAX_NOTE):
            base, accidentals, _ = base_accidentals_octave(str(random.choice(self.notes)))
            result = text_to_note("{}{}{}".format(base, accidentals, random_octave_for_char(base)))
        return result


if __name__ == "__main__":
    random.seed(int(sys.argv[-1]))

    rules_included = list(map(int, sys.argv[1].split('_')))
    min_n = int(sys.argv[2])
    max_n = int(sys.argv[3])
    min_mutations = int(sys.argv[4])
    max_mutations = int(sys.argv[5])
    mutation_type = sys.argv[6]

    assert max(rules_included) <= 4 and min(rules_included) >= 1
    assert mutation_type in ["any", "immutable_rests", "move_rests"]

    scale_transpose = random.randint(0, 11)
    scale_base = text_to_note('C0').transpose(scale_transpose)
    scale_type = random.choice(SCALE_TYPES)
    scale = Scale(scale_base, scale_type)

    n = random.randint(min_n, max_n)
    num_mutations = random.randint(min_mutations, max_mutations)
    text_conversion_choices = ["standard"]

    if 2 in rules_included:
        text_conversion_choices.append("sharpify")
        text_conversion_choices.append("flatify")
        
    transpose_by = 0
    if 4 in rules_included:
        transpose_by = random.randint(-6*12, 6*12)
    elif 3 in rules_included:
        transpose_by = random.randint(-6, 6) * 12

    MIN_NOTE = text_to_note('A0')
    MAX_NOTE = text_to_note('C8')
    if transpose_by < 0:
        MIN_NOTE = MIN_NOTE.transpose(-transpose_by)
    elif transpose_by > 0:
        MAX_NOTE = MAX_NOTE.transpose(-transpose_by)
    song1 = [scale.random_note(True, MIN_NOTE, MAX_NOTE) for _ in range(n)]
    song2 = [note.transpose(transpose_by) for note in song1]
    
    for _ in range(num_mutations):
        i = -1
        while True:
            i = random.randint(0, n-1)
            if mutation_type == "immutable_rests":
                if not song2[i].is_rest():
                    break
            elif mutation_type == "move_rests":
                if song2[i].is_rest():
                    break
            else:
                break
        if mutation_type == "any":
            song2[i] = scale.random_note(True)
        elif mutation_type == "move_rests":
            song2[i-1], song2[i] = song2[i], song2[i-1]
        else:
            song2[i] = scale.random_note(False)

    print(n)
    print(' '.join('{}'.format(x.to_string(random.choice(text_conversion_choices))) for x in song1))
    print(' '.join('{}'.format(x.to_string(random.choice(text_conversion_choices))) for x in song2))
