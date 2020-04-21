import sys

usage = "usage: ./xlogin.py <a-zA-Z string>"

cypher = {
"a":".-",
"b":"-...", 
"c":"-.-.", 
"d":"-..", 
"e":".", 
"f":"..-.", 
"g":"--.", 
"h":"....", 
"i":"..", 
"j":".---", 
"k":"-.-", 
"l":".-..", 
"m":"--", 
"n":"-.", 
"o":"---", 
"p":".--.", 
"q":"--.-", 
"r":".-.", 
"s":"...", 
"t":"-", 
"u":"..-", 
"v":"...-", 
"w":".--", 
"x":"-..-", 
"y":"-.--", 
"z":"--..",
" ":" "
}

if len(sys.argv) != 2 or len(sys.argv[1]) == 0 or not sys.argv[1].replace(" ","").isalpha():
    print(usage)
    exit()
else :
    string = sys.argv[1].lower()
    print("".join([cypher[w] for w in string]))
