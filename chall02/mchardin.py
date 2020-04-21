import sys
import re
import string

def main(args=None):
    if args is None or len(args) != 1:
        print("usage: ./mchardin.py <a-zA-Z string>")
        exit()
    right_chars = re.compile("[" + string.ascii_letters + " " + "]")
    if len(args[0]) == 0 or len(args[0]) != len(re.findall(right_chars, args[0])):
        print("usage: ./mchardin.py <a-zA-Z string>")
        exit()
    to_morse = args[0].upper()
    morse_list = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
    for i in range(len(to_morse)):
        if to_morse[i] == ' ':
            print(" ", end='')
        else:
            print(morse_list[ord(to_morse[i]) - ord('A')], end='')
    print("")

if __name__ == "__main__":
    main(sys.argv[1::])