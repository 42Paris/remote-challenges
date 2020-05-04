#!/usr/bin/python3
import sys
import re


class UsageException(Exception):
    pass


def main():
    if len(sys.argv) < 2:
        raise UsageException
    rule = re.compile(r'[a-zA-Z\s]+')
    if not rule.match(sys.argv[1]):
        raise UsageException

    morse_map = {
        'a': '.-',
        'b': '-...',
        'c': '-.-.',
        'd': '-..',
        'e': '.',
        'f': '..-.',
        'g': '--.',
        'h': '....',
        'i': '..',
        'j': '.---',
        'k': '-.-',
        'l': '.-..',
        'm': '--',
        'n': '-.',
        'o': '---',
        'p': '.--.',
        'q': '--.-',
        'r': '.-.',
        's': '...',
        't': '-',
        'u': '..-',
        'v': '...-',
        'w': '.--',
        'x': '-..-',
        'y': '-.--',
        'z': "--..",
        ' ': ' '
    }

    def get_morse_char(letter):
        return morse_map[letter.lower()]

    print(''.join([get_morse_char(letter) for letter in sys.argv[1]]))


if __name__ == "__main__":
    try:
        main()
    except UsageException:
        print(f'Usage: {sys.argv[0]} <a-zA-Z string>')
