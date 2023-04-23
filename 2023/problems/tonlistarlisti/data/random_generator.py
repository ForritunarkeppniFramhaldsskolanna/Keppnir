#!/usr/bin/python3
import sys
import random

chars = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '_']
last_song, last_len = -1, 1
def new_song():
    global last_song, last_len
    last_song += 1
    if last_song == 27 ** last_len:
        last_len += 1
        last_song = 0
    nam = []
    x = last_song
    for i in range(last_len):
        nam.append(chars[x % 27])
        x //= 27
    return ''.join(nam)

random.seed(int(sys.argv[-1]))

q = eval(sys.argv[1])
typ = eval(sys.argv[2])
maxlen = eval(sys.argv[3])

print(q)

if typ == 1:
    songs = []
    for i in range(q):
        r = random.randint(1, 3)
        if len(songs) == 0:
            r = random.randint(2, 3)
        if r == 1:
            print('P', random.randint(1, 10 ** 9))
        elif r == 2:
            si, li = new_song(), random.randint(1, maxlen)
            songs.append(si)
            print('L', si, li)
        else:
            if random.randint(1, 10) != 10 and len(songs) > 0:
                print('Q', random.choice(songs))
            else:
                print('Q', new_song())
else:
    lens = dict()
    songs = []
    playlist = set()
    for i in range(q):
        r = random.randint(1, 3)
        if len(playlist) == 0:
            r = random.randint(2, 3)
        if r == 1:
            print('P', random.randint(1, 10 ** 9))
        elif r == 2:
            if len(songs) > 0 and random.randint(1, 3) == 1:
                si = random.choice(songs)
                if si in playlist:
                    playlist.remove(si)
                else:
                    playlist.add(si)
                print('L', si, lens[si])
            else:
                si, li = new_song(), random.randint(1, maxlen)
                songs.append(si)
                lens[si] = li
                playlist.add(si)
                print('L', si, li)
        else:
            if random.randint(1, 20) != 10 and len(songs) > 0:
                print('Q', random.choice(songs))
            else:
                print('Q', new_song())
    
