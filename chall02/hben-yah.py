import sys
import re

morseDic = {
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
'z':'--..'
}

def usage():
	print("usage: ./hben-yah.py <a-zA-Z string>")
	exit()

def str_replace(text, dic):
    rc = re.compile('|'.join(map(re.escape, dic)))
    def trans(match):
        return dic[match.group(0)]
    return rc.sub(trans, text)


if len(sys.argv) != 2:
	usage()

word = sys.argv[1]
if not re.match("^[A-Za-z0-9 ]*$", word) or len(word) == 0:
	usage()

morse = str_replace(word.lower(), morseDic)

print(morse)