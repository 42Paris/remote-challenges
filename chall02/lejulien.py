# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    lejulien.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lejulien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 17:21:09 by lejulien          #+#    #+#              #
#    Updated: 2020/04/20 21:18:02 by lejulien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

MORSE = { 'A':'.-', 'B':'-...', 'C':'-.-.', 'D':'-..', 'E':'.',
          'F':'..-.', 'G':'--.', 'H':'....', 'I':'..', 'J':'.---',
          'K':'-.-', 'L':'.-..', 'M':'--', 'N':'-.', 'O':'---',
          'P':'.--.', 'Q':'--.-', 'R':'.-.', 'S':'...', 'T':'-',
          'U':'..-', 'V':'...-', 'W':'.--', 'X':'-..-', 'Y':'-.--',
          'Z':'--..'}

if (len(sys.argv) == 2 and len(sys.argv[1]) > 0):
    if (all(x.isalpha() or x.isspace() for x in sys.argv[1])):
        sys.argv[1] = sys.argv[1].upper()
        for x in sys.argv[1]:
            if (x == ' '):
                print(x, end='')
            else:
                print(MORSE[x], end='')
        print('')
    else:
        print('usage: ./lejulien.py <a-zA-Z string>')
else:
    print('usage: ./lejulien.py <a-zA-Z string>')

