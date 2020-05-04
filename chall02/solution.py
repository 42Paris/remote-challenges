#!/usr/bin/env python3

import string
import sys

raw_codes = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --.."
code_map = {k: v for k, v in zip(string.ascii_lowercase, raw_codes.split(" "))}

def smorse(input_str):
    return "".join(code_map[c] for c in input_str)


if len(sys.argv) != 3:
    print(f"usage: ./{sys.argv[1]}.py <a-zA-Z string>")
    exit(1)


for av in sys.argv[2].split(" "):
    if not av.isalpha():
        print(f"usage: ./{sys.argv[1]}.py <a-zA-Z string>")
        exit(1)

lowercase = sys.argv[2].lower()
print(" ".join(smorse(av) for av in lowercase.split(" ")))
