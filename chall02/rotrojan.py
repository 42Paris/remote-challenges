#!/usr/bin/env python3


from sys import argv


morse = {
    'a': ".-",
    'b': "-...",
    'c': "-.-.",
    'd': "-..",
    'e': ".",
    'f': "..-.",
    'g': "--.",
    'h': "....",
    'i': "..",
    'j': ".---",
    'k': "-.-",
    'l': ".-..",
    'm': "--",
    'n': "-.",
    'o': "---",
    'p': ".--.",
    'q': "--.-",
    'r': ".-.",
    's': "...",
    't': "-",
    'u': "..-",
    'v': "...-",
    'w': ".--",
    'x': "-..-",
    'y': "-.--",
    'z': "--.."
}


def check_args(args):
    if len(args) != 2:
        return False
    if len(args[1]) == 0:
        return False
    if not all(char.isalpha() or char.isspace() for char in args[1]):
        return False
    return True


def main():
    if check_args(argv) is False:
        print("usage: ./rotrojan.py <a-zA-Z string>")
    else:
        for char in argv[1]:
            for letter in morse.keys():
                if char.casefold() == letter:
                    print(morse[letter], end='')
                elif char == ' ':
                    print(' ', end='')
                    break
        print()


if __name__ == "__main__":
    main()
