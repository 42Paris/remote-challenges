#!/usr/bin/env python

import sys
import re

regex = re.compile('[^ a-zA-Z0-9]')

if len(sys.argv) > 2 or len(sys.argv) < 2 or not sys.argv[1] or regex.findall(sys.argv[1]):
    print('usage: ./cmiran.py <a-zA-Z string>')
    exit()

dictionnary = {
        'a': '.-', 'b': '-...',  'c': '-.-.', 'd': '-..', 'e': '.', 'f': '..-.', 'g': '--.',
        'h': '....', 'i': '..', 'j': '.---', 'k': '-.-', 'l': '.-..', 'm': '--', 'n': '-.',
        'o': '---', 'p': '.--.', 'q': '--.-', 'r': '.-.', 's': '...', 't': '-', 'u': '..-',
        'v': '...-', 'w': '.--', 'x': '-..-', 'y': '-.--', 'z': '--..'
}

message = sys.argv[1].lower().replace(' ', '')

for letter in message:
    print(dictionnary[letter], end = '', sep = '')
print()
