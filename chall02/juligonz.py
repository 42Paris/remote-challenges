#!/usr/bin/env python3

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    juligonz.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 14:15:41 by juligonz          #+#    #+#              #
#    Updated: 2020/04/20 15:28:46 by juligonz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

dict_morse = {
    'a' : ".-",
    'b' : "-...",
    'c' : "-.-.",
    'd' : "-..",
    'e' : ".",
    'f' : "..-.",
    'g' : "--.",
    'h' : "....",
    'i' : "..",
    'j' : ".---",
    'k' : "-.-",
    'l' : ".-..",
    'm' : "--",
    'n' : "-.",
    'o' : "---",
    'p' : ".--.",
    'q' : "--.-",
    'r' : ".-.",
    's' : "...",
    't' : "-",
    'u' : "..-",
    'v' : "...-",
    'w' : ".--",
    'x' : "-..-",
    'y' : "-.--",
    'z' : "--..",
    ' ' : " "
}

def print_usage():
    print("usage:", sys.argv[0], "<a-zA-Z string>")

if len(sys.argv) != 2 or not sys.argv[1]:
    print_usage()
    sys.exit()

try:
    print("".join([dict_morse[c]  for c in sys.argv[1].lower()]))
except KeyError:
    print_usage()
