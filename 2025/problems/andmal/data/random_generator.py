#!/usr/bin/python3
import sys
import random
import string

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "single":
    poss = string.ascii_letters + string.digits + " "
    ind = int(sys.argv[2]) - 1
    print(poss[ind])

if typ == "empty":
    print("")

if typ == "full":
    print("aaaaaaaaaa")

if typ == "special":
    ind = int(sys.argv[2]) - 1
    specials = [
        "password",
        "12345",
        "123",
        "asdf",
        "hunter2",
        "batman",
        "superman",
        "lol",
        "ASDF",
        "asdfghjkl",
        "qwerty",
        "qwertyuiop",
        "zxcv",
        "zxcvbnm",
        "secret",
        "123456",
        "123456789",
        "12345678",
        "111111",
        "123123",
        "1234567890",
        "qwerty123",
        "000000",
        "1q2w3e",
        "aa12345678",
        "abc123",
        "123321",
        "password1",
        "letmein",
        "admin",
        "starwars",
        "football",
        "dragon",
        "monkey",
        "passw0rd",
        "master",
        "login",
        "jesus",
        "baseball",
        "spes",
        "bull",
    ]
    print(specials[ind])
