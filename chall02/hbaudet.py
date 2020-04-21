#!/usr/bin/python3

import sys

letters = [".-",
"-..." ,
"-.-." ,
"-.." ,
"." ,
"..-." ,
"--." ,
"...." ,
".." ,
".---" ,
"-.-" ,
".-.." ,
"--" ,
"-." ,
"---" ,
".--." ,
"--.-" ,
".-." ,
"..." ,
"-" ,
"..-" ,
"...-" ,
".--" ,
"-..-" ,
"-.--" ,
"--.."]

if len(sys.argv) != 2 :
	sys.exit("usage: ./hbaudet.py <a-zA-Z string>")
if len(sys.argv[1]) < 1:
	sys.exit("usage: ./hbaudet.py <a-zA-Z string>")
for i in sys.argv[1]:
	if not i.isalpha() and not i == ' ':
		print("usage: ./hbaudet.py <a-zA-Z string>")
		sys.exit()
for i in sys.argv[1]:
	if i == ' ':
		print(i, end = '')
	else:
		print(letters[ord(i.lower()) - ord('a')], end='')
print()
