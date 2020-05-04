#!/usr/bin/python3
import sys

morse = dict(A='.-', B='-... ', C='-.-.', D='-..', E='.', F='..-.', G='--.',
             H='....', I='..', J='.---', K='-.-', L='.-..', M='--', N='-.',
             O='---', P='.--.', Q='--.-', R='.-.', S='...', T='-', U='..-',
             V='...-', W='.--', X='-..-', Y='-.--', Z='--..')

def main():
    if len(sys.argv) == 2 and len(sys.argv[1]) > 0:
        print(morse_string(sys.argv[1]))
    else:
        print("usage: ./charoua.py <a-zA-Z string>")

def morse_string(str):
    if "".join(str.split()).isalpha():
        new = "".join((morse_char(c)) for c in str)
        return new
    else :
        return "usage: ./charoua.py <a-zA-Z string>"

def morse_char(c):
    if c.isalpha():
        return morse[c.upper()]
    else:
        return c

if __name__ == "__main__":
     main()
