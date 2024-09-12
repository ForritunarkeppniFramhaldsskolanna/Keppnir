#!/usr/bin/python3
import sys

qwerty = '~1234567890-=qwertyuiop[]asdfghjkl;\'zxcvbnm,./ '
dvorak = '~1234567890[]\',.pyfgcrl/=aoeuidhtns-;qjkxbmwvz '
bjarki = '0248613579=-/bjarkigust.,loempdcnvq;[]yzhwfx\'~ '

dat = sys.stdin.readlines()
frm, _, to = dat[0].strip().split()
frm, to = eval(frm), eval(to)
outp = []
for c in dat[1][:-1]:
    i = frm.index(c)
    outp.append(to[-i])
print("".join(outp))
