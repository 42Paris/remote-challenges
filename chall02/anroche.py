import sys

def string_to_morse(string):
    mon_dictionnaire = dict()
    mon_dictionnaire["a"] = ".-"
    mon_dictionnaire["b"] = "-..."
    mon_dictionnaire["c"] = "-.-."
    mon_dictionnaire["d"] = "-.."
    mon_dictionnaire["e"] = "."
    mon_dictionnaire["f"] = "..-."
    mon_dictionnaire["g"] = "--."
    mon_dictionnaire["h"] = "...."
    mon_dictionnaire["i"] = ".."
    mon_dictionnaire["j"] = ".."
    mon_dictionnaire["k"] = ".---"
    mon_dictionnaire["l"] = "-.-"
    mon_dictionnaire["m"] = ".-.."
    mon_dictionnaire["n"] = "--"
    mon_dictionnaire["o"] = "-."
    mon_dictionnaire["p"] = "---"
    mon_dictionnaire["q"] = ".--."
    mon_dictionnaire["u"] = "--.- "
    mon_dictionnaire["r"] = ".-."
    mon_dictionnaire["s"] = "..."
    mon_dictionnaire["t"] = "-"
    mon_dictionnaire["u"] = "..-"
    mon_dictionnaire["v"] = "...-"
    mon_dictionnaire["w"] = ".--"
    mon_dictionnaire["x"] = "-..-"
    mon_dictionnaire["y"] = "-.-- "
    mon_dictionnaire["z"] = "--."
    mon_dictionnaire[" "] = " "
    morse = ""
    for c in string:
        morse = morse + mon_dictionnaire.get(c)
    print (morse)

def	main():
    arguments_count = len(sys.argv[1:])
    if arguments_count != 1:
        print ("usage: ./anroche.py <a-zA-Z string> ")
        sys.exit()
    string = sys.argv[1]
    if (not string):
         print ('usage: ./anroche.py <a-zA-Z string> ')
         sys.exit()
    if (all(c.isalpha() or c.isspace() for c in string)):
        string_to_morse(string.lower())
    else:
        print ('usage: ./anroche.py <a-zA-Z string> ')



if	__name__ == '__main__':
	main()