#!/usr/local/bin/python3
import sys
import re

def usage():
    print("usage: " + sys.argv[0] + " <a-zA-Z string>")

def match_regex(text):
    if re.compile("^[a-zA-Z ]*$").match(text) is None:
        return False
    return True

def valid_input():
    if len(sys.argv) == 2:
        if len(sys.argv[1]) != 0:
            if match_regex(sys.argv[1]) is True:
                return True
    return False

def morse_encode(text):
    morse_alphabet = {  "a": ".-", "b": "-...", "c": "-.-.",
                        "d": "-..", "e": ".", "f": "..-.",
                        "g": "--.", "h": "....", "i": "..",
                        "j": ".---", "k": "-.-", "l": ".-..",
                        "m": "--", "n": "-.", "o": "---",
                        "p": ".--.", "q": "--.-", "r": ".-.",
                        "s": "...", "t": "-", "u": "..-",
                        "v": "...-", "w": ".--", "x": "-..-",
                        "y": "-.--", "z": "--..", " ": " "}
    morse_encoded = ""
    for char in text:
        morse_encoded += morse_alphabet[char.lower()]
    return morse_encoded

def main():
    if valid_input() is True:
        print(morse_encode(sys.argv[1]))
    else:
        usage()

if __name__ == "__main__":
    main()
