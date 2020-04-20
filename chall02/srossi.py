#!/usr/bin/env python
import sys

morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--."]

if __name__ == "__main__":
  if len(sys.argv) != 2 or not all(x.isalpha() or x.isspace() for x in sys.argv[1]) or len(sys.argv[1])<1:
    print('usage: ./srossi.py <a-zA-Z string>')
    exit()
  for c in sys.argv[1].lower():
    print (morse[ord(c)-97], end='') if c != ' ' else print (' ', end='')
  print()
