#!/usr/bin/env python3
import sys

dict = {' ': ' ', 'a': '.-', 'b': '-...', 'c': '-.-.', 'd': '-..', 'e': '.', 'f': '..-. ', 'g': '--.', 'h': '....', 'i': '..', 'j': '.---', 'k': '-.-', 'l': '.-..', 'm': '--', 'n': '-.', 'o': '---',  'p': '.--.', 'q': '--.-', 'r': '.-.', 's': '...', 't': '-', 'u': '..-', 'v': '...-', 'w': '.--','x': '-..-', 'y': '-.--', 'z': '--..'}

if (len(sys.argv) != 2) or len(sys.argv[1]) < 1 or not (sys.argv[1].replace(' ','') + 'a').isalpha():
  print("usage: ./aguiot--.py <a-zA-Z string>")
  sys.exit(0)

print(''.join(dict[char] for char in sys.argv[1].lower()))
