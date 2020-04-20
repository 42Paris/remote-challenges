#!/usr/bin/python3
import sys

if len(sys.argv) != 2:
    print("usage: ./fyusuf-a <a-zA-Z string>")
    sys.exit(0)
if sys.argv[1] == "":
    print("usage: ./fyusuf-a <a-zA-Z string>")
    sys.exit(0)
str = sys.argv[1]
for i in range(len(str)):
    if not str[i].isalpha() and not str[i] == ' ':
        print("usage: ./fyusuf-a <a-zA-Z string>")
        sys.exit(0)
str = sys.argv[1].lower()
alphabet = {
   'a':'.-',
   'b':'-...',
   'c':'-.-.',
   'd':'-..',
   'e':'.',
   'f':'..-.',
   'g':'--.',
   'h':'....',
   'i':'..',
   'j':'.---',
   'k':'-.-',
   'l':'.-..',
   'm':'--',
   'n':'-.',
   'o':'---',
   'p':'.--.',
   'q':'--.-',
   'r':'.-.',
   's':'...',
   't':'-',
   'u':'..-',
   'v':'...-',
   'w':'.--',
   'x':'-..-',
   'y':'-.--',
   'z':'--..',
   ' ':''
}
ret = ''
for i in range(len(str)):
    ret += alphabet[str[i]]
print(ret, sep='')
