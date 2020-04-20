#!/usr/bin/env python
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    xlogin.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 15:39:59 by hthomas           #+#    #+#              #
#    Updated: 2020/04/20 15:40:22 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import string

if __name__ == "__main__":
    if not len(sys.argv) == 2 or (len(sys.argv) == 2 and (len(sys.argv[1]) == 0 or not all(x.isalpha() or x.isspace() for x in sys.argv[1]))):
        print('usage: ./xlogin.py <a-zA-Z string>')
    else:
        file = open("morse.txt", "r")
        lines = file.readlines()
        file.close()
        s = ""
        for letter in sys.argv[1].lower():
                if letter == ' ':
                    s += ' '
                else:
                    s += lines[string.lowercase.index(letter)][:-1]
        print(s)
