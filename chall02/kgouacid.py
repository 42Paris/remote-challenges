#!/usr/bin/env python3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kgouacid.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 14:17:43 by kgouacid          #+#    #+#              #
#    Updated: 2020/04/20 14:43:28 by kgouacid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import string
import sys

def get_dictionary():
	keys =  string.ascii_lowercase
	values = """.-
-... 
-.-. 
-.. 
. 
..-. 
--. 
.... 
.. 
.--- 
-.- 
.-.. 
-- 
-. 
--- 
.--. 
--.- 
.-. 
... 
- 
..- 
...- 
.-- 
-..- 
-.-- 
--..""".replace(' ', '').split('\n')
	return dict(zip(keys, values))

def error(fname):
	print("usage: " + fname + " <a-zA-Z string>")
	exit()

def translate(word):
	kv = get_dictionary()
	kv[' '] = ' '
	for c in word.lower():
		print (kv[c], end='')
def main():
	args = sys.argv
	if (len(args) != 2) or (not args[1].replace(' ', '').isalpha()):
		error(args[0])
	translate(args[1])

if __name__ == "__main__":
    main()
