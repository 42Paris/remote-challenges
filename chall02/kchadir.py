#
#  @author kchadir
#
# this program written in python allows you to transcode a message into morse code
# the message must be a character string only no number or special characters
# one and only one argument is allowed when the program is called
#
# first we put in miniscule all the characters of the string
# then we loop through the string and for each character we look for its Morse code in the dictionary
# at the end we return the result
#

import sys

def string2morse():
    dico_morse = {"a" : ".-", "b" : "-...", "c" : "-.-.", "d" : "-..",
                  "e" : ".", "f" : "..-.", "g" : "--.", "h" : "....",
                  "i" : "..", "j" : ".---", "k" : "-.-", "l" : ".-..",
                  "m" : "--", "n" : "-.", "o" : "---", "p" : ".--.",
                  "q" : "--.-", "r" : ".-.", "s" : "...", "t" : "-",
                  "u" : "..-", "v" : "...-","w" : ".--", "x" : "-..-",
                  "y" : "-.--", "z" : "--..", " " : " "}

    arv = sys.argv[1:]
    if (len(arv) != 1 or not arv[0] or not (all(i.isalpha() or i.isspace() for i in arv[0]))):
        print("usage: ./kchadir.py <a-zA-Z string>")
        exit()

    res = ""
    for key in arv[0].lower():
        res += dico_morse[key]

    return res

if __name__ == "__main__":
    print(string2morse())
