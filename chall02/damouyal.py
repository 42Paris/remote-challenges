#!python
import sys

morse_dict =    { 'A':'.-', 'B':'-...', 
                  'C':'-.-.', 'D':'-..', 'E':'.', 
                  'F':'..-.', 'G':'--.', 'H':'....', 
                  'I':'..', 'J':'.---', 'K':'-.-', 
                  'L':'.-..', 'M':'--', 'N':'-.', 
                  'O':'---', 'P':'.--.', 'Q':'--.-', 
                  'R':'.-.', 'S':'...', 'T':'-', 
                  'U':'..-', 'V':'...-', 'W':'.--', 
                  'X':'-..-', 'Y':'-.--', 'Z':'--..'} 

def fail_exit():
   print("usage: ./damouyal.py <a-zA-Z String>")
   sys.exit()


argc = len(sys.argv)

if argc != 2:
    fail_exit()
else:
    my_string = sys.argv[1].upper()
    out_string = ''
    size = len(my_string)
    cur = 0
    while (cur < size):
        if (my_string[cur].isspace()):
            out_string = out_string + my_string[cur]
        elif (my_string[cur] in morse_dict):
            out_string = out_string + morse_dict[my_string[cur]]
        else:
            exit_fail()
        cur = cur + 1
    print (out_string)
