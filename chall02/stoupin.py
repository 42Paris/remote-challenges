#!/usr/bin/python3
import string
import sys

morse_code = {letter: code for letter, code in zip(string.ascii_lowercase, """.-
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
--..""".split())}

def encode_char(c):
    return morse_code[c.lower()] if c.isalpha() else c

def encode_string(s):
    return "".join(encode_char(c) for c in s)

def main():
    if len(sys.argv) == 2 and len(sys.argv[1]) > 0 and "".join(sys.argv[1].split()).isalpha():
        print(encode_string(sys.argv[1]))
    else:
        print(f"usage: ./stoupin.py <a-zA-Z string>")

if __name__ == "__main__":
    main()
