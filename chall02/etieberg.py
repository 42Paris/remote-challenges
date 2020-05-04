#!/usr/bin/env python3

import sys
import re

morse_code = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-" , ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

if __name__ == "__main__":
	try:
		if not len(sys.argv) == 2:
			raise ValueError
		text = str(sys.argv[1])
		if text is None:
			raise ValueError
		if not text:
			raise ValueError
		s = text.split()
		for chunk in s: 
			if not chunk.isalpha():
				raise ValueError
	except ValueError:
		print("usage: {} <a-zA-Z string>".format(sys.argv[0]))
		sys.exit()
	string = text.lower()
	morse = zip(alphabet, morse_code)
	morse_dict = dict(morse)
	for c in string:
		if c.isspace():
				sys.stdout.write(c)
		else:
			sys.stdout.write(morse_dict[c])
	sys.stdout.write('\n')
