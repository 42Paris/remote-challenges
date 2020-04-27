#!/usr/bin/env python3

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mbenjell.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/21 02:28:42 by mbenjell          #+#    #+#              #
#    Updated: 2020/04/21 04:21:53 by mbenjell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import re

if __name__ == '__main__':
    
    regex = r"^[a-zA-Z ]+$"

    if len(sys.argv) != 2 or re.match(regex, sys.argv[1]) is None:
        print('usage: ./mbenjell.py <a-zA-Z string>')
        exit()

    string = sys.argv[1]
    morse = ""
    data = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --.." 

    string = string.lower()
    list = data.split(' ')
    list.append(' ')
    alphabet = "abcdefghijklmnopqrstuvwxyz "
    for l in string:
        morse += list[alphabet.find(l)] 
    print(morse)
