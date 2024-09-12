#!/usr/bin/python3
# Define the mapping between the keyboard layouts
keyboard_mappings = {
    'qwerty': "~1234567890-=qwertyuiop[]asdfghjkl;\'zxcvbnm,./",
    'dvorak': "~1234567890[]',.pyfgcrl/=aoeuidhtns-;qjkxbmwvz",
    'bjarki': "02148653179=-bjakigsutloervmcdnpqvqzwhfx\'~,./~" # I added tilde manually
}

def translate_text(from_layout, to_layout, text):
    from_keys = keyboard_mappings[from_layout]
    to_keys = keyboard_mappings[to_layout]
    translation_map = str.maketrans(from_keys, to_keys)
    return text.translate(translation_map)

if __name__ == "__main__":
    # Read the input
    input_line = input().strip().split()
    from_layout, to_layout = input_line[0], input_line[2]
    text = input().strip()

    # Translate and print the intended text
    translated_text = translate_text(to_layout, from_layout, text)
    print(translated_text)

