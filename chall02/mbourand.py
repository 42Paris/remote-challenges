#!/usr/bin/env python3

import sys
import string

ALPHABET =	{	
				'A':'.-', 'B':'-...', 'C':'-.-.', 
				'D':'-..', 'E':'.', 'F':'..-.',
				'G':'--.', 'H':'....', 'I':'..',
				'J':'.---', 'K':'-.-', 'L':'.-..',
				'M':'--', 'N':'-.',  'O':'---', 
				'P':'.--.', 'Q':'--.-', 'R':'.-.',
				'S':'...', 'T':'-',  'U':'..-',
				'V':'...-', 'W':'.--', 'X':'-..-',
				'Y':'-.--', 'Z':'--..', ' ':' '
			}

AUTHORIZED_CHARACTERS = set(string.ascii_letters + ' ')

def str2morse(str):
	str = str.upper()
	for c in str:
		print(ALPHABET[c], end='')
	print("")

if __name__ == "__main__":
	if (len(sys.argv) != 2 or not set(sys.argv[1]).issubset(AUTHORIZED_CHARACTERS) or len(sys.argv[1]) == 0):
		print("usage: ./mbourand.py <a-zA-Z string>")
	else:
		str2morse(sys.argv[1])
