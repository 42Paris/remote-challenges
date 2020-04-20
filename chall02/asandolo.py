#!/usr/bin/env python3
import sys
import re

dict = {'a': '.-', 'b': '-...', 'c': '-.-.', 'd': '-..', 'e': '.', 'f': '..-. ', 'g': '--.',
        'h': '....', 'i': '..', 'j': '.---', 'k': '-.-', 'l': '.-..', 'm': '--', 'n': '-.',
        'o': '---',  'p': '.--.', 'q': '--.-', 'r': '.-.', 's': '...', 't': '-', 'u': '..-',
        'v': '...-', 'w': '.--','x': '-..-', 'y': '-.--', 'z': '--..', ' ': ' '}


def can_use(argv):
    if len(argv) != 2:
        return 0
    if not argv[1].strip():
        return 0
    if not re.match("^[A-Za-z ]*$", argv[1]):
        return 0
    return 1


def usage_and_exit():
    print("usage: ./asandolo.py <a-zA-Z string>")
    exit(1)


def main():
    if not can_use(sys.argv):
        usage_and_exit()
    str = list(sys.argv[1].lower().strip())
    end = ""
    for s in str:
        end += dict[s]
    print(end)


if __name__ == '__main__':
    main()
