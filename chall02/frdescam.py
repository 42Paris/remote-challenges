#! /usr/bin/python3

import sys
import re

translation_table = dict(
        a=".-",
        b="-...",
        c="-.-.",
        d="-..",
        e=".",
        f="..-. ",
        g="--.",
        h="....",
        i="..",
        j=".---",
        k="-.-",
        l=".-..",
        m="--",
        n="-.",
        o="---",
        p=".--.",
        q="--.-",
        r=".-.",
        s="...",
        t="-",
        u="..-",
        v="...-",
        w=".--",
        x="-..-",
        y="-.--",
        z="--..")

def convert_char(char) :
    if char == ' ' :
        return ' '
    else :
        return translation_table[char]

def exit_with_input_error() :
    print("usage: ./frdescam.py <a-zA-Z string>")
    exit()

if len(sys.argv) != 2 or not sys.argv[1] or not re.match("^[A-Za-z\s]*$", sys.argv[1]):
    exit_with_input_error()

input_str = sys.argv[1].lower()
out_str = ""
for char in input_str :
    out_str += convert_char(char)
print(out_str)
