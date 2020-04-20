import sys
import re

MORSE_CODE = {
    'A': '.-', 'B': '-...',
    'C': '-.-.', 'D': '-..', 'E': '.',
    'F': '..-.', 'G': '--.', 'H': '....',
    'I': '..', 'J': '.---', 'K': '-.-',
    'L': '.-..', 'M': '--', 'N': '-.',
    'O': '---', 'P': '.--.', 'Q': '--.-',
    'R': '.-.', 'S': '...', 'T': '-',
    'U': '..-', 'V': '...-', 'W': '.--',
    'X': '-..-', 'Y': '-.--', 'Z': '--..',
    ' ': ' '
}

def to_morse(msg):
    return "".join([MORSE_CODE[letter] for letter in msg.upper()])

if __name__ == "__main__":
    if len(sys.argv) == 2 and sys.argv[1] != "" and re.fullmatch(r"[a-zA-Z ]*", sys.argv[1]):
        print(to_morse(sys.argv[1]))
    else:
        print("usage: ./xlogin.py <a-zA-Z string>")