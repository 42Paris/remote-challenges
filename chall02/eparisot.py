#! /usr/bin/python3

import sys

morse = {
    "a":".-",
    "b":"-...",
    "c":"-.-.",
    "d":"-..",
    "e":".",
    "f":"..-.",
    "g":"--.",
    "h":"....",
    "i":"..",
    "j":".---",
    "k":"-.-",
    "l":".-..",
    "m":"--",
    "n":"-.",
    "o":"---",
    "p":".--.",
    "q":"--.-",
    "r":".-.",
    "s":"...",
    "t":"-",
    "u":"..-",
    "v":"...-",
    "w":".--",
    "x":"-..-",
    "y":"-.--",
    "z":"--.."
}

def translate(c):
    return morse[c.lower()]

def error():
    print("usage: ./eparisot.py <a-zA-Z string>")
    exit()

if __name__ == "__main__":
    if len(sys.argv) < 1:
        error()
    res = []
    for arg in sys.argv[1:]:
        if len(arg) == 0 or not arg.isalpha():
            error()
        morse_arg = "".join(list(map(translate, arg)))
        res.append(morse_arg)
    print(" ".join(res))

