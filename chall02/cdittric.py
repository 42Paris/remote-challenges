#!/usr/bin/python3
import sys

morse = [
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

if (len(sys.argv) != 2 or len(sys.argv[1]) == 0):
    print("usage: ", sys.argv[0], " <a-zA-Z string>")
    sys.exit();

for c in sys.argv[1]:
    if not (c.isalpha() or c.isspace()):
        print("usage: ", sys.argv[0], " <a-zA-Z string>")
        sys.exit();

for c in sys.argv[1]:
    if c == ' ':
        print(' ', end='')
    elif c.islower():
        print(morse[ord(c) - ord('a')], end='')
    else:
        print(morse[ord(c) - ord('A')], end='')
print("")
