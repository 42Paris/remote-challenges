import sys, getopt

def mymorse(argv):
    listem = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."];
    usage = "usage: ./ymarcill.py <a-zA-Z string>"
    if len(argv) != 1 or argv[0].isalpha() is False:
        print(usage);
        return;
    for letter in argv[0] :
        if letter.isupper() :
            sys.stdout.write(listem[ord(letter) - 65]);
        elif letter.islower():
            sys.stdout.write(listem[ord(letter) - 97]);
    print("");

if __name__ == '__main__':
    mymorse(sys.argv[:0:-1])
