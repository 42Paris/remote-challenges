#!/usr/bin/env python3

from sys import argv, stderr
from string import ascii_lowercase

morse_values = [
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
]
morse = {k: v for k, v in zip(ascii_lowercase, morse_values)}


def isAlphaString(s):
    return all([True if c in morse or c == " " else False for c in s.lower()])


def encode(s):
    return "".join([morse[c] if c in morse else c for c in s.lower()])


if __name__ == "__main__":
    if len(argv) == 2 and argv[1] and isAlphaString(argv[1]):
        print(encode(argv[1]))
    else:
        print("usage: ./jergauth.py <a-zA-Z string>", file=stderr)
