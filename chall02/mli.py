#!/usr/bin/env python3

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mli.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 14:16:23 by mli               #+#    #+#              #
#    Updated: 2020/04/20 14:44:20 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

sys.argv.pop(0)

args = list(sys.argv)

morse_dict = {'A':'.-', 'B':'-...', 'C':'-.-.', 'D':'-..', 'E':'.', 'F':'..-.',
            'G':'--.', 'H':'....', 'I':'..', 'J':'.---', 'K':'-.-', 'L':'.-..',
            'M':'--', 'N':'-.', 'O':'---', 'P':'.--.', 'Q':'--.-', 'R':'.-.',
            'S':'...', 'T':'-', 'U':'..-', 'V':'...-', 'W':'.--','X':'-..-',
            'Y':'-.--', 'Z':'--..', ' ' : ' '}

argc = len(args)
if (argc != 1 or len(args[0]) == 0):
    print("usage: ./mli.py <a-zA-Z string>")
    exit(1)

for words in args:
    for char in words:
        if (char.upper() not in morse_dict.keys()):
            print("usage: ./mli.py <a-zA-Z string>")
            exit(1)

for words in args:
    words = words.upper()
    for chars in words:
        print(morse_dict[chars], end="")
print("")
